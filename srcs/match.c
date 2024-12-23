#include <dirent.h>
#include <stdio.h>

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

void	rec_dir(DIR *dir_ptr, char **sep, int depth, char *base_path, const int max_depth)
{
	char	full_path[1024 + 1];
	DIR	*sub_dir;
	s_dir	*idk;

	while ((idk = readdir(dir_ptr)) != NULL)
	{
		if (!ft_strcmp(idk->d_name, ".") || !ft_strcmp(idk->d_name, ".."))
			continue ; 
		ft_strcpy(full_path, base_path);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, idk->d_name);
		printf("[[%s]]\n", full_path);
		if (idk->d_type == DT_DIR)
		{
			if (depth < max_depth - 1 && match(sep[depth], (char *)idk->d_name))
			{
				sub_dir = opendir(full_path);
				if (!sub_dir)
					return ;
				rec_dir(sub_dir, sep, depth + 1, full_path, max_depth);
				closedir(sub_dir);
			}
		}
		else if (idk->d_type == DT_REG)
		{
			if (depth < max_depth - 1 && match(sep[depth], (char *)idk->d_name))
				printf("REGULAR FILE MATCH:\n\td_name: [%s]\n\n", idk->d_name);
		}
		else
			printf("other: d_name:\n\t[%s]\n\n", idk->d_name);
	}
}

int	check_open_dir(char *path, char **sep, int size)
{
	DIR	*dir_ptr;

	if (!path)
		return (1);
	dir_ptr = opendir(path);
	if (!dir_ptr)
		return (printf("could not open the base dir\n"));
	rec_dir(dir_ptr, sep, 0, path, size - 2);
	closedir(dir_ptr);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	check_open_dir(argv[1], argv + 2, argc);
	//printf("%d\n", match(argv[1], argv[2]));
	return (0);
}

