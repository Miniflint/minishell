/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_cmdli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:29:03 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:09 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../printfd/HEADER/ft_printfd.h"

void	view_cmdli(t_cmdli *cmdli)
{
	t_unlist	*tokens;

	while (cmdli)
	{
		tokens = cmdli->tokens;
		ft_printfd(1, "Tokens :\n");
		while (tokens)
		{
			ft_printfd(1, " - %s\n", tokens->token);
			tokens = tokens->next;
		}
		ft_printfd(1, "Andor    : %d\n", cmdli->and_or);
		ft_printfd(1, "Pipe out : %p\n", cmdli->pipe_out);
		ft_printfd(1, "P in     : %d\n", cmdli->create_fork);
		ft_printfd(1, "P out    : %d\n", cmdli->exit_fork);
		ft_printfd(1, "P lvl    : %d\n", cmdli->p_lvl);
		cmdli = cmdli->next;
	}
}

void	edit_p_lvl(t_cmdli *cmdli)
{
	int	new_lvl;

	new_lvl = 0;
	while (cmdli)
	{
		new_lvl += cmdli->create_fork;
		cmdli->p_lvl = new_lvl;
		new_lvl -= cmdli->exit_fork;
		cmdli = cmdli->next;
	}
}
