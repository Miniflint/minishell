/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:12:23 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/02 01:58:03 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

unsigned int	path_counter(char *path)
{
	unsigned int	count;

	count = 0;
	while (*path)
	{
		if (*path && *path != ':' && (!*(path + 1) || *(path + 1) == ':'))
			count++;
		path++;
	}
	return (count);
}

char	**split_path(char *path, char *cmd, unsigned int cmd_len)
{
	char			**ret;
	char			*path_i;
	unsigned int	i;
	unsigned int	j;

	path_i = path;
	ret = malloc((path_counter(path) + 1) * sizeof(char *));
	if (!ret)
		return (free_path(NULL, path));
	j = 0;
	while (*path_i)
	{
		while (*path_i == ':')
			path_i++;
		i = 0;
		while (path_i[i] && path_i[i] != ':')
			i++;
		ret[j] = path_join(path_i, cmd, i, cmd_len);
		if (!ret[j++])
			return (free_path(ret, path));
		path_i += i;
	}
	free_path(NULL, path);
	ret[j] = NULL;
	return (ret);
}

char	*get_absolute_path(char *cmd, char *path)
{
	char			**path_tab;
	char			*ret;
	unsigned int	i;

	if (!path || !*path)
		return (no_path(cmd, path));
	if (ft_strchr_path(cmd, path, '/'))
		return (ft_strdup(cmd));
	path_tab = split_path(path, cmd, ft_strlen(cmd));
	if (!path_tab)
		return (ft_strdup(cmd));
	i = 0;
	while (path_tab[i] && access(path_tab[i], X_OK) == -1)
		i++;
	if (!path_tab[i])
	{
		free_tab(path_tab);
		g_errno = 127;
		ft_printfd(2, "#+wminishell#0: %s: #/rcommand not found#0\n", cmd);
		return (NULL);
	}
	ret = ft_strdup(path_tab[i]);
	free_tab(path_tab);
	return (ret);
}
