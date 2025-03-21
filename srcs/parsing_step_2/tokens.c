/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:29:22 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:29:23 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*__get_is_first(int *__is_first, int *i)
{
	static int	*is_first;

	if (__is_first)
	{
		is_first = __is_first;
		*is_first = 1;
		if (i)
			*i = 0;
	}
	return (is_first);
}

void	add_new_tok(t_cmdli *cmdli, char *cursor, int *is_first,
	unsigned int len)
{
	if (cursor)
	{
		if (*is_first)
		{
			*is_first = 0;
			cmdli->tok_cursor->token = ft_strldup(cursor, len);
			if (!cmdli->tok_cursor->token)
				return ;
		}
		else
		{
			if (cmdli->tok_cursor->type == ARG
				|| cmdli->tok_cursor->type == CMD)
				new_unlist(cmdli, ft_strldup(cursor, len), ARG);
			else if (!cmdli->cmd_error)
			{
				cmdli->cmd_error = 1;
				ft_printfd(2, "#+minishell#0: %s:#/r ambigous redirect#0\n",
					cmdli->tok_cursor->token);
				g_errno = 1;
			}
		}
	}
}

void	random_hehe(t_cmdli *cmdli, char **cursor, char *quote, int *i)
{
	while ((*cursor)[(*i)] && (*cursor)[(*i)] != ' '
		&& (*cursor)[(*i)] != '\'' && (*cursor)[(*i)] != '"')
		++(*i);
	if ((*cursor)[(*i)] == '\'' || (*cursor)[(*i)] == '"')
	{
		*quote = (*cursor)[(*i)++];
		while ((*cursor)[(*i)] && (*cursor)[(*i)] != *quote)
			++(*i);
		if ((*cursor)[(*i)])
			++(*i);
	}
	if ((*cursor)[(*i)] == ' ')
	{
		add_new_tok(cmdli, (*cursor),
			__get_is_first(NULL, NULL), (unsigned int)(*i));
		(*cursor) += *i + 1;
		while (*(*cursor) == ' ')
			++(*cursor);
		*i = 0;
	}
}

void	split_tokens(t_cmdli *cmdli)
{
	int			is_first;
	int			i;
	char		quote;
	char *const	tmp = cmdli->tok_cursor->token;
	char		*cursor;

	cursor = tmp;
	__get_is_first(&is_first, &i);
	while (*cursor == ' ')
		++cursor;
	if (!*cursor)
	{
		if (tmp)
			free(tmp);
		cmdli->tok_cursor->token = ft_strdup("");
		if (!cmdli->tok_cursor->token)
			malloc_error(&cmdli);
		return ;
	}
	cmdli->tok_cursor->token = NULL;
	while (cursor[i])
		random_hehe(cmdli, &cursor, &quote, &i);
	if (i && cursor[i - 1] != ' ')
		add_new_tok(cmdli, cursor, __get_is_first(NULL, NULL), i);
	free(tmp);
}

void	clean_tokens(t_cmdli *cmdli)
{
	t_unlist	*tmp;

	tmp = NULL;
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (!cmdli->tok_cursor->token || !*cmdli->tok_cursor->token)
		{
			if (tmp)
				tmp->next = cmdli->tok_cursor->next;
			else
				cmdli->tokens = cmdli->tokens->next;
			if (cmdli->tok_cursor->token)
				free(cmdli->tok_cursor->token);
			free(cmdli->tok_cursor);
			cmdli->tok_cursor = tmp;
		}
		else
			cmdli->tok_cursor->token = remove_quote(cmdli->tok_cursor->token);
		tmp = cmdli->tok_cursor;
		if (tmp)
			cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
}
