/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdli_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:19 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:20 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_strcmp_int(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (0);
	return (1);
}

int	ft_strslen(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	**ft_strsjoin(char *s, char **ss)
{
	char			**ret;
	unsigned int	i;

	ret = malloc((ft_strslen(ss) + 2) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	if (ss)
	{
		while (ss[i])
		{
			ret[i] = ss[i];
			++i;
		}
	}
	ret[i] = s;
	ret[++i] = 0;
	return (ret);
}

int	files_len(t_file **files)
{
	int	i;

	if (!files)
		return (0);
	i = 0;
	while (files[i])
		i++;
	return (i);
}

t_file	**file_join(char *file, t_file **files, t_type type)
{
	t_file			**ret;
	unsigned int	i;

	ret = malloc((files_len(files) + 2) * sizeof(t_file *));
	if (!ret)
		return (NULL);
	i = 0;
	if (files)
	{
		while (files[i])
		{
			ret[i] = files[i];
			++i;
		}
	}
	ret[i] = malloc(sizeof(t_file));
	if (ret[i])
	{
		ret[i]->name = file;
		ret[i]->type = type;
	}
	ret[++i] = 0;
	return (ret);
}
