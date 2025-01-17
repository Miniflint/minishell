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
	if (!ft_strcmp(d_name, ".") || !ft_strcmp(d_name, ".."))
		return (1);
	if (depth)
	{
		f_ft_strcpy(full_path, base_path);
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
		if (idk->d_name[0] == '.' && info.sep[0][0] != '.')
			continue ;
		if (skip_add_path(info.full_path, idk->d_name, info.base_path, depth))
				continue ;
		get_name = NULL;
		if (idk->d_type == DT_DIR)
		{
			if ((info.infinite == -1 || depth <= info.true_max_depth) &&
				match(info.sep[get_depth(depth, info.true_max_depth)], (char *)idk->d_name))
			{
				sub_info.dir_ptr = opendir(info.full_path);
				sub_info.base_path = info.full_path;
				if (!sub_info.dir_ptr)
					return ;
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
void parse_param_recdir(char *s, int *wiar, int *ews, int *is_first)
{
	int			slash;
	char const	*tmp = s;

	slash = 0;
	*is_first = 1;
	*wiar = 0;
	*ews = 0;
	while (*s)
	{
		if (*s == '*' && *(s + 1) && *(s + 1) == '*')
			*wiar = 1;
		s++;
	}
	while (*(tmp++))
	{
		if (*tmp == '/')
			slash++;
		if (*tmp && !*(tmp + 1) && *tmp == '/')
			*ews = 1;
	}
	if (*wiar >= 1 && slash > 0)
		*wiar = -1;
	else
		*wiar = 0;
}

// TODO:
// take sep as char * and add a split for /
// implement rules in TODO.md
void	check_open_dir(char *path, char *separators, t_cmdli *cmdli)
{
	t_match	info;
	int		i;
	int	param;

	if (!path)
		return ;
	info.dir_ptr = opendir(path);
	if (!info.dir_ptr)
	{
		ft_printfd(2, "could not open the base dir, non gerer dans match.c ligne 131\n");
		return ;
	}
	info.sep = ft_split(separators, '/');
	i = 0;
	while (info.sep[i])
		i++;
	info.true_max_depth = i - 1;
	info.base_path = path;
	parse_param_recdir(separators, &info.infinite, &info.dir_or_file, &param);
	rec_dir(info, 0, cmdli, &param);
	i = 0;
	while (info.sep[i])
		free(info.sep[i++]);
	free(info.sep);
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

