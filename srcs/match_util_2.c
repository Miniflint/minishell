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
	if (!path || !info->sep[i])
		return (NULL);
	tmp = ft_strjoin(path, info->sep[i]);
	free(path);
	if (!tmp)
		return (NULL);
	new_path = ft_strjoin(tmp, "/");
	free(tmp);
	free(info->sep[i]);
	if (!new_path)
		return (NULL);
	info->sep[i] = NULL;
	return (new_path);
}

void	assign_info_base_path(t_match *info, char *separators)
{
	int		i;
	char	*path;

	i = 0;
	path = get_path_sep(info, separators);
	if (!path)
		path = ft_strdup(".");
	if (info->absolute_path)
		info->base_path = ft_strjoin("/", path);
	else
		info->base_path = ft_strdup(path);
	info->base_path = remove_quote(info->base_path);
	free(path);
	while (info->sep[i])
		i++;
	info->max_depth_file = i - 1;
	info->max_depth_dir = i - 1;
	if (i > 1)
		info->max_depth_dir = i - 2;
}
