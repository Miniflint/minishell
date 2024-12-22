#include <stdio.h>
#include <dirent.h>

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
char **split(char *s, char c);

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
void	rec_dir(DIR *dir_ptr)
{
	const s_dir	*idk = readdir(dir_ptr);
	if (!idk)
		return ;
	if (idk->d_type == DT_DIR)
		printf("DIRECTORY:\n\td_name: [%s]\n\n", idk->d_name);
	else if (idk->d_type == DT_REG)
		printf("REGULAR FILE:\n\td_name: [%s]\n\n", idk->d_name);
	else
		printf("other: d_name:\n\t[%s]\n\n", idk->d_name);
	return (rec_dir(dir_ptr));
}

void	check_open_dir(char *path)
{
	DIR	*dir_ptr;

	if (!path)
		return ;
	dir_ptr = opendir(path);
	rec_dir(dir_ptr);
	closedir(dir_ptr);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	check_open_dir(argv[2]);
	//printf("%d\n", match(argv[1], argv[2]));
	return (0);
}

