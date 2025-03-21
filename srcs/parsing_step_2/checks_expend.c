/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_expend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:29:02 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:29:03 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pass_until_char(char **s, char c)
{
	++*s;
	while (**s && **s != c)
		++*s;
	if (**s)
		++*s;
}

int	check_wildcard(char *s)
{
	while (*s)
	{
		if (*s == '\'' || *s == '"')
			pass_until_char(&s, *s);
		else if (*s == '*')
			return (1);
		else
			++s;
	}
	return (0);
}

int	check_var(char *s)
{
	char	quote;

	quote = 0;
	while (*s)
	{
		if (*s == '"')
			quote = !quote;
		if (!quote && *s == '\'')
			pass_until_char(&s, '\'');
		else if (*s == '$' && (ft_isalnum(s[1]) || s[1] == '?'))
			return (1);
		else
			++s;
	}
	return (0);
}
