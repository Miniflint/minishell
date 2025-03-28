/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:14 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:21 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*add_var_free(char *str, char *new)
{
	char	*tmp;
	char	*ret;

	tmp = str;
	ret = NULL;
	if (!new)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	ret = ft_strjoin(str, new);
	free(new);
	if (tmp)
		free(tmp);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*add_home(unsigned int *i)
{
	++*i;
	return (ft_get_var("HOME"));
}

char	*add_var(char **cmdline, char *str, unsigned int *i)
{
	unsigned int	j;
	char			*new;
	char			*tmp;

	j = 0;
	++*i;
	while (ft_is_alphanum_((*cmdline)[*i + j]))
		j++;
	if ((*cmdline)[*i] == '?' && !j)
		j++;
	if (j)
	{
		tmp = ft_substr((*cmdline), *i, j);
		new = ft_get_var(tmp);
		if (tmp)
			free(tmp);
	}
	else if ((*cmdline)[*i] != '"' && (*cmdline)[*i] != '\'')
		new = ft_strdup("$");
	else
		new = ft_strdup("");
	*i += j;
	return (add_var_free(str, new));
}
