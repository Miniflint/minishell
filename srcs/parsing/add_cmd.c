/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:54:52 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/02 18:00:30 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_cmd(t_cmdli **cmds_list, char *cmd, t_type *type)
{
	add_arg(cmds_list, cmd, type);
	*type = CMD;
	if (*cmds_list)
		(*cmds_list)->cmd = (*cmds_list)->cmd_args[0];
}
