/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:32 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:17 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	new_unlist(t_cmdli *cmdli, char *s, t_type type)
{
	t_unlist	*tmp;

	if (!cmdli->tokens)
	{
		cmdli->tokens = malloc(sizeof(t_unlist));
		if (!cmdli->tokens)
			return (1);
		cmdli->tokens->token = s;
		cmdli->tokens->type = type;
		cmdli->tokens->next = NULL;
		cmdli->tok_cursor = cmdli->tokens;
	}
	else
	{
		tmp = cmdli->tok_cursor->next;
		cmdli->tok_cursor->next = malloc(sizeof(t_unlist));
		if (!cmdli->tok_cursor->next)
			return (1);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
		cmdli->tok_cursor->token = s;
		cmdli->tok_cursor->type = type;
		cmdli->tok_cursor->next = tmp;
	}
	return (0);
}
