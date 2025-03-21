/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:08 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:24 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_pipe(t_cmdli **cmds_list, t_type *type)
{
	*type = PIPE;
	(*cmds_list)->next = create_cmdli();
	if (!(*cmds_list)->next)
		return (error_cmdli(cmds_list, "memory allocation failed\n"));
	(*cmds_list)->next->previous = (*cmds_list);
	if (!(*cmds_list)->pipe_out)
	{
		(*cmds_list)->pipe_out = malloc(2 * sizeof(int));
		(*cmds_list)->pipe_out[0] = -1;
		(*cmds_list)->pipe_out[1] = -1;
	}
	(*cmds_list)->next->pipe_in = (*cmds_list)->pipe_out;
	*cmds_list = (*cmds_list)->next;
}
