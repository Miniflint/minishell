/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:34 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:16 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_parenthesis(t_cmdli **cmds_list, t_shell *shell, t_type *type)
{
	*type = OPEN_P;
	++shell->parenthesis;
	++(*cmds_list)->create_fork;
}

void	close_parenthesis(t_cmdli **cmds_list, t_shell *shell, t_type *type)
{
	*type = CLOSE_P;
	--shell->parenthesis;
	++(*cmds_list)->exit_fork;
}

int	check_close_parenthesis(char *s, char *token, t_shell *shell, t_type type)
{
	return (ft_strcmp_int(s, token) && shell->parenthesis - 1 >= 0
		&& (type == CMD || type == ARG || type == RFILE || type == CLOSE_P));
}
