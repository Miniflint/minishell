#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
typedef struct dirent t_dir;
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
	else if (*s1 == '/' && *s2 != '/')
		return (0);
	else if (!*s2)
		return (0);
	else if (*s1 == '*' && (match(s1, s2 + 1) || match(s1 + 1, s2)))
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	return (0);
}

int	skip_add_path(char full_path[1024 + 1], char *d_name, char *base_path, int depth)
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

void	add_token_unlist(t_cmdli *cmdli, char *name, char *is_first)
{
	if (name)
	{
		if (*is_first)
		{
			*is_first = 0;
			free(cmdli->tok_cursor->token);
			cmdli->tok_cursor->token = ft_strdup(name);
			if (!cmdli->tok_cursor->token)
			{
				ft_printfd(2, "Erreur de malloc non gerer dans match.c ligne 94\n");
				return ;
			}
		}
		else
		{
			if (cmdli->tok_cursor->type == ARG || cmdli->tok_cursor->type == CMD)
				new_unlist(cmdli, ft_strdup(name), ARG);
			else
				ft_printfd(2, "Erreur ambigous redirect non gerer dans match.c ligne 103\n");
		}
	}
}

void	rec_dir(DIR *dir_ptr, char **sep, int depth, char *base_path, const int max_depth, t_cmdli *cmdli, int dir_or_file, char *is_first)
{
	char	full_path[PATH_MAX];
	DIR	*sub_dir;
	t_dir	*idk;
	char	*get_name;

	while ((idk = readdir(dir_ptr)) != NULL)
	{
		if (skip_add_path(full_path, idk->d_name, base_path, depth))
				continue ;
		if (max_depth == -1)
			depth = 0;
		get_name = NULL;
		if (idk->d_type == DT_DIR)
		{
			if ((max_depth == -1 || depth <= max_depth) && match(sep[depth], (char *)idk->d_name))
			{
				sub_dir = opendir(full_path);
				if (!sub_dir)
					return ;
				get_name = full_path;
				rec_dir(sub_dir, sep, depth + 1, full_path, max_depth, cmdli, dir_or_file, is_first);
				closedir(sub_dir);
			}
		}
		else if((max_depth == -1 || depth == max_depth) && !dir_or_file && match(sep[max_depth], (char *)idk->d_name))
			get_name = full_path;
		add_token_unlist(cmdli, get_name, is_first);
	}
}


// TODO:
// take sep as char * and add a split for /
// implement rules in TODO.md
void	check_open_dir(char *path, char *separators, t_cmdli *cmdli)
{
	DIR	*dir_ptr;
	char	**sep;
	int		i;
	char	is_first;

	if (!path)
		return ;
	dir_ptr = opendir(path);
	if (!dir_ptr)
	{
		ft_printfd(2, "could not open the base dir, non gerer dans match.c ligne 131\n");
		return ;
	}
	sep = ft_split(separators, '/');
	i = 0;
	while (sep[i])
		i++;
	printf("%d\n", i);
	is_first = 1;
	rec_dir(dir_ptr, sep, 0, path, -1, cmdli, 0, &is_first);
	i = 0;
	while (sep[i])
		free(sep[i++]);
	free(sep[i]);
	closedir(dir_ptr);
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

