#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/*
 struct dirent {
    ino_t	d_ino; //file number of this entry
    __uint16_t	d_reclen; //length of the entry record
    __uint8_t	d_type; // FILE TYPE
    __uint8_t	d_namlen; // LEN NAME
    char	d_name[256 + 1]; //name of the file
 };
*/
typedef struct dirent s_dir;
char	*ft_strcat(char *dest, char *src);
void	ft_strcpy(char *dst, char *src);
int	ft_strcmp(const char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);


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

int	skip_add_path(char full_path[1024 + 1], char *d_name, char *base_path, const int dir_or_file)
{
	if (!ft_strcmp(d_name, ".") || !ft_strcmp(d_name, ".."))
		return (1);
	ft_strcpy(full_path, base_path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, d_name);
	if (dir_or_file == 1)
		ft_strcat(full_path, "/");
	return (0);
}

void	rec_dir(DIR *dir_ptr, char **sep, int depth, char *base_path, const int max_depth, const int dir_or_file, char **rtn)
{
	char	full_path[1024 + 1];
	DIR	*sub_dir;
	s_dir	*idk;
	char	*get_name;

	while ((idk = readdir(dir_ptr)) != NULL)
	{
		if (skip_add_path(full_path, idk->d_name, base_path, dir_or_file))
			continue ;
		get_name = NULL;
		if (idk->d_type == DT_DIR)
		{
			if ((max_depth == -1 || depth <= max_depth) && match(sep[depth], (char *)idk->d_name))
			{
				sub_dir = opendir(full_path);
				if (!sub_dir)
					return ;
				if (dir_or_file == 1)
					get_name = full_path;
				rec_dir(sub_dir, sep, depth + 1, full_path, max_depth, dir_or_file, rtn);
				closedir(sub_dir);
			}
		}
		if (!dir_or_file && depth == max_depth && match(sep[max_depth], (char *)idk->d_name))
			get_name = full_path;
		if (get_name)
		{
			char *tmp = ft_strjoin(*rtn, full_path);
			free(*rtn);
			*rtn = ft_strjoin(tmp, " ");
			free(tmp);
		}
	}
}

int	check_open_dir(char *path, char **sep, int size)
{
	DIR	*dir_ptr;
	char	*str;

	if (!path)
		return (1);
	dir_ptr = opendir(path);
	if (!dir_ptr)
		return (printf("could not open the base dir\n"));
	rec_dir(dir_ptr, sep, 0, path, size, 0, &str);
	closedir(dir_ptr);
	printf("%s\n", str);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	check_open_dir(argv[1], argv + 2, argc - 3);
	//printf("%d\n", match(argv[1], argv[2]));
	return (0);
}

