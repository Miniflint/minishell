/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:03:54 by hermesrolle       #+#    #+#             */
/*   Updated: 2025/01/12 07:16:56 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include <stdio.h>

char	*split_cmd(char **cmdline, unsigned int *i, char c)
{
	printf("split_cmd in\n");
	unsigned int	j;

	j = 0;
	while ((*cmdline)[*i + j] && ((*cmdline)[*i + j] == c))
		++j;
	*i += j;
	printf("split_cmd out\n");
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
	// if (((*cmdline)[*i] && (*cmdline)[*i] == '$'))
	// 	return (add_var(cmdline, ret, i));
	// if ((*cmdline)[*i] == '~')
	// 	return (add_home(i));
	if ((*cmdline)[*i] && (*cmdline)[*i] == '\'')
		return (add_quote(cmdline, ret, i));
	else if ((*cmdline)[*i] && (*cmdline)[*i] == '"')
		return (add_dquote(cmdline, ret, i));
	return (ret);
}

// char	*split_cmd_sp(char **cmdline, unsigned int *i)
// { //ne pas gerer ici ~, $ et *
// 	unsigned int	j;
// 	char			*ret;

// 	printf("split_cmd_sp in\n");
// 	ret = NULL;
// 	while ((*cmdline)[*i] && (*cmdline)[*i] != ' ' && (*cmdline)[*i]
// 		!= '<' && (*cmdline)[*i] != '>' && (*cmdline)[*i]
// 		!= '|' && (*cmdline)[*i] != '&' && (*cmdline)[*i] != '('
// 		&& (*cmdline)[*i] != ')')
// 	{
// 		j = 0;
// 		while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != ' '
// 			&& (*cmdline)[*i + j] != '<' && (*cmdline)[*i + j] != '>'
// 			&& (*cmdline)[*i + j] != '|' && (*cmdline)[*i + j] != '&'
// 			&& (*cmdline)[*i + j] != '(' && (*cmdline)[*i + j] != ')'
// 			&& (*cmdline)[*i + j] != '\'' && (*cmdline)[*i + j]
// 			!= '"' && !(!j && !ret && ((*cmdline)[*i + j + 1] == '/'
// 			|| (*cmdline)[*i + j + 1] == ' ' || !(*cmdline)[*i + j + 1])))
// 			++j;
// 		if (!j && (*cmdline)[*i + j] != '\'' && (*cmdline)[*i + j] != '"')
// 		{
// 			printf("split_cmd_sp_ret in\n");
// 			return (ret);
// 			printf("split_cmd_sp_ret out\n");
// 		}
// 		else if (j)
// 			ret = split_cmd_sp_ret(cmdline, ret, i, j);
// 		*i += j;
// 		printf("split_cmd_sp_add_func in\n");
// 		ret = split_cmd_sp_add_func(cmdline, ret, i);
// 		printf("split_cmd_sp_add_func out\n");
// 	}
// 	printf("split_cmd_sp out\n");
// 	return (ret);
// }

char	*split_cmd_sp(char **cmdline, unsigned int *i)
{
	unsigned int	j;
	char			*ret;

	ret = NULL;
	while ((*cmdline)[*i] && (*cmdline)[*i] != ' ' && (*cmdline)[*i]
		!= '<' && (*cmdline)[*i] != '>' && (*cmdline)[*i]
		!= '|' && (*cmdline)[*i] != '&')
	{
		j = 0;
		while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != '$'
			&& (*cmdline)[*i + j] != ' ' && (*cmdline)[*i + j]
			!= '<' && (*cmdline)[*i + j] != '>' && (*cmdline)[*i + j]
			!= '|' && (*cmdline)[*i + j] != '&' && (*cmdline)[*i + j]
			!= '\'' && (*cmdline)[*i + j] != '"' && !(!j && !ret
			&& (*cmdline)[*i + j] == '~' && ((*cmdline)[*i + j + 1] == '/'
			|| (*cmdline)[*i + j + 1] == ' ' || !(*cmdline)[*i + j + 1])))
			++j;
		if (j)
			ret = split_cmd_sp_ret(cmdline, ret, i, j);
		*i += j;
		ret = split_cmd_sp_add_func(cmdline, ret, i);
	}
	return (ret);
}
