#include "minishell.h"
#include "../printfd/HEADER/ft_printfd.h"

/*
 struct dirent {
    ino_t	d_ino; //file number of this entry
    __uint16_t	d_reclen; //length of the entry record
    __uint8_t	d_type; // FILE TYPE
    __uint8_t	d_namlen; // LEN NAME
    char	d_name[256 + 1]; //name of the file
 };
*/
// typedef struct dirent t_dir;


// char	*ft_strcat(char *dest, char *src);
// void	ft_strcpy(char *dst, char *src);
// int	ft_strcmp(const char *s1, char *s2);
// char	*ft_strjoin(char *s1, char *s2);

// char interpret qui se desinterpret si la valeur est la meme que celle d'entree:
// interpret = "
// desinterpret si un autre char "
int match(char *s1, char *s2)
{
	if ((*s1 == '*' && !*(s1 + 1)) || (!*s1 && !*s2))
		return (1);
	else if (!*s2)
		return (0);
	else if (*s1 == '*' && (match(s1, s2 + 1) || match(s1 + 1, s2)))
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	return (0);
}

int	skip_add_path(char full_path[PATH_MAX], char *d_name, char *base_path, int depth)
{
	if (!ft_strcmp(base_path, "."))
		if (!ft_strcmp(d_name, ".") || !ft_strcmp(d_name, ".."))
			return (1);
	if (depth || (!depth && ft_strcmp(base_path, ".")))
	{
		f_ft_strcpy(full_path, base_path);
		if (depth)
			f_ft_strcat(full_path, "/");
		f_ft_strcat(full_path, d_name);
	}
	else
		f_ft_strcpy(full_path, d_name);
	return (0);
}

char *dup_file_name(char *name, int dir_or_file)
{
	char	*ret;
	int		i;

	ret = malloc((ft_strlen(name) + 1 + dir_or_file) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (name[i])
	{
		ret[i] = name[i];
		++i;
	}
	if (dir_or_file)
		ret[i++] = '/';
	ret[i] = '\0';
	return (ret);
}

void	add_token_unlist(t_cmdli *cmdli, char *name, int *is_first, int dir_or_file)
{
	if (name)
	{
		if (*is_first)
		{
			*is_first = 0;
			free(cmdli->tok_cursor->token);
			cmdli->tok_cursor->token = dup_file_name(name, dir_or_file);
			if (!cmdli->tok_cursor->token)
			{
				ft_printfd(2, "Erreur de malloc non gerer dans match.c ligne 94\n");
				return ;
			}
		}
		else
		{
			if (cmdli->tok_cursor->type == ARG || cmdli->tok_cursor->type == CMD)
				new_unlist(cmdli, dup_file_name(name, dir_or_file), ARG);
			else
				ft_printfd(2, "Erreur ambigous redirect non gerer dans match.c ligne 103\n");
		}
	}
}

int	get_depth(int depth, int max_depth)
{
	if (depth > max_depth)
		return (max_depth);
	return (depth);
}

void	rec_dir(t_match info, int depth, t_cmdli *cmdli, int *is_first)
{
	t_match	sub_info;
	t_dir	*idk;
	char	*get_name;

	sub_info = info;
	while ((idk = readdir(info.dir_ptr)) != NULL)
	{
		if (skip_add_path(info.full_path, idk->d_name, info.base_path, depth))
			continue ;
		if (idk->d_name[0] == '.' && info.sep[0][0] != '.')
			continue ;
		get_name = NULL;
		if (idk->d_type == DT_DIR)
		{
			if ((info.infinite == -1 || depth <= info.true_max_depth) &&
				match(info.sep[get_depth(depth, info.true_max_depth)], (char *)idk->d_name))
			{
				sub_info.dir_ptr = opendir(info.full_path);
				if (!sub_info.dir_ptr)
				{
					ft_printfd(2, "could not open the base dir, non gerer dans match.c ligne 123\n");
					return ;
				}
				sub_info.base_path = info.full_path;
				if ((!info.true_max_depth || depth <= info.true_max_depth))
					get_name = info.full_path;
				add_token_unlist(cmdli, get_name, is_first, info.dir_or_file);
				rec_dir(sub_info, depth + 1, cmdli, is_first);
				closedir(sub_info.dir_ptr);
			}
		}
		else if((info.infinite == -1 || depth == info.true_max_depth) &&
			!info.dir_or_file && match(info.sep[info.true_max_depth], (char *)idk->d_name))
		{
			get_name = info.full_path;
			add_token_unlist(cmdli, get_name, is_first, info.dir_or_file);
		}
	}
}


// wiar == Wildcard In A Row
// ews == Ends With Slash
void parse_param_recdir(char *s, t_match *info, int *is_first)
{
	int			slash;
	char const	*tmp = s;

	slash = 0;
	*is_first = 1;
	info->dir_or_file = 0;
	info->infinite = 0;
	info->absolute_path = 0;
	if (*s == '/')
		info->absolute_path = 1;
	while (*s)
	{
		if (*s == '*' && *(s + 1) && *(s + 1) == '*')
			info->infinite = 1;
		s++;
	}
	while (*(tmp++))
	{
		if (*tmp == '/')
			slash++;
		if (*tmp && !*(tmp + 1) && *tmp == '/')
			info->dir_or_file = 1;
	}
	if (info->infinite >= 1 && slash > 0)
		info->infinite = -1;
	else
		info->infinite = 0;
}

char	*get_path_sep(t_match *info, char *separators)
{
	int		i;
	int		j;
	char	*tmp;
	char	*path;

	info->sep = ft_split(separators, '/');
	info->sep_base_ptr = info->sep;
	i = 0;
	path = NULL;
	tmp = NULL;
	while (info->sep[i])
	{
		j = 0;
		while (info->sep[i][j])
		{
			if (info->sep[i][j] == '*')
			{
				info->sep += i;
				return (path);
			}
			j++;
		}
		if (info->sep[i][j] != '*')
		{
			tmp = ft_strjoin(path, info->sep[i]);
			if (tmp)
				free(path);
			path = ft_strjoin(tmp, "/");
			free(tmp);
			free(info->sep[i]);
			info->sep[i] = NULL;
		}
		i++;
	}
	return (path);
}

// TODO:
// take sep as char * and add a split for /
// implement rules in TODO.md
void	check_open_dir(char *separators, t_cmdli *cmdli)
{
	t_match	info;
	int		param;
	char	*path;
	int		i;

	parse_param_recdir(separators, &info, &param);
	path = get_path_sep(&info, separators);
	if (!path)
		path = ft_strdup(".");
	if (info.absolute_path)
		info.base_path = ft_strjoin("/", path);
	else
		info.base_path = ft_strdup(path);
	i = 0;
	while (info.sep[i])
		i++;
	info.true_max_depth = i - 1;
	info.dir_ptr = opendir(info.base_path);
	if (!info.dir_ptr)
	{
		ft_printfd(2, "could not open the base dir, non gerer dans match.c ligne 131\n");
		return ;
	}
	printf("a_p:%d - d_o_f:%d - inf:%d - t_m_d:%d\n", info.absolute_path, info.dir_or_file, info.infinite, info.true_max_depth);
	rec_dir(info, 0, cmdli, &param);
	i = 0;
	while (info.sep[i])
		free(info.sep[i++]);
	free(info.sep_base_ptr);
	if (path)
		free(path);
	free(info.base_path);
	closedir(info.dir_ptr);
}

// int main(int argc, char **argv)
// {
// 	char *str;

// 	if (argc < 3)
// 		return (1);
// 	str = check_open_dir(argv[1], argv + 2, argc - 3);
// 	printf("%s\n", str);
// 	return (0);
// }

