/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:26:39 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:27:02 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

char	**free_path(char **tab, char *path)
{
	if (tab)
		free_tab(tab);
	if (path)
		free(path);
	return (NULL);
}

char	*path_join(char *path, char *cmd,
				unsigned int path_len, unsigned int cmd_len)
{
	char			*ret;
	unsigned int	i;

	ret = malloc((path_len + cmd_len + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < path_len)
		ret[i++] = *(path++);
	ret[i++] = '/';
	while (*cmd)
		ret[i++] = *(cmd++);
	ret[i] = 0;
	return (ret);
}

char	*no_path(char *cmd, char *path)
{
	if (path)
		free(path);
	if (access(cmd, X_OK) == -1)
	{
		g_errno = 127;
		ft_printfd(2, "#+wminishell#0: %s: #/r%s#0\n", cmd, "command not found");
		return (NULL);
	}
	return (ft_strdup(cmd));
}
