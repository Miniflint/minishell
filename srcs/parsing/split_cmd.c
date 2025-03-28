/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:35 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:16 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	*split_cmd(char **cmdline, unsigned int *i, char c)
{
	unsigned int	j;

	j = 0;
	while ((*cmdline)[*i + j] && ((*cmdline)[*i + j] == c))
		++j;
	*i += j;
	return (ft_substr((*cmdline), *i - j, j));
}

char	*split_cmd_sp_ret(char	**cmdline, char *ret,
		unsigned int *i, unsigned int j)
{
	char	*tmp;
	char	*new;

	tmp = ret;
	new = ft_substr(*cmdline, *i, j);
	if (!new)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	ret = ft_strjoin(tmp, new);
	free(new);
	if (tmp)
		free(tmp);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*split_cmd_sp_add_func(char **cmdline, char *ret, unsigned int *i)
{
	if ((*cmdline)[*i] && (*cmdline)[*i] == '\'')
		return (add_quote(cmdline, ret, i));
	else if ((*cmdline)[*i] && (*cmdline)[*i] == '"')
		return (add_dquote(cmdline, ret, i));
	return (ret);
}

char	*split_cmd_sp(char **cmdline, unsigned int *i)
{
	unsigned int	j;
	char			*ret;

	ret = NULL;
	while ((*cmdline)[*i] && (*cmdline)[*i] != ' '
		&& (*cmdline)[*i] != '<' && (*cmdline)[*i] != '>'
		&& (*cmdline)[*i] != '|' && (*cmdline)[*i] != '&'
		&& (*cmdline)[*i] != '(' && (*cmdline)[*i] != ')')
	{
		j = 0;
		while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != ' '
			&& (*cmdline)[*i + j] != '<' && (*cmdline)[*i + j] != '>'
			&& (*cmdline)[*i + j] != '|' && (*cmdline)[*i + j] != '&'
			&& (*cmdline)[*i + j] != '\'' && (*cmdline)[*i + j] != '"'
			&& (*cmdline)[*i + j] != '(' && (*cmdline)[*i + j] != ')')
			++j;
		if (j)
			ret = split_cmd_sp_ret(cmdline, ret, i, j);
		*i += j;
		ret = split_cmd_sp_add_func(cmdline, ret, i);
	}
	return (ret);
}
