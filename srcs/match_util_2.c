#include "minishell.h"

void	parse_param_recdir(char *s, t_match *info, int *is_first)
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
}

char	*join_path_free(t_match *info, char *path, int i)
{
	char	*tmp;
	char	*new_path;

	tmp = NULL;
	new_path = NULL;
	tmp = ft_strjoin(path, info->sep[i]);
	if (!tmp)
		return (NULL);
	free(path);
	new_path = ft_strjoin(tmp, "/");
	if (!new_path)
		return (NULL);
	free(tmp);
	free(info->sep[i]);
	info->sep[i] = NULL;
	return (new_path);
}