/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:05 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:25 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	add_cmd(t_cmdli *cmdli, char *cmd)
{
	int	ret;

	ret = add_arg(cmdli, cmd);
	if (cmdli)
		cmdli->cmd = cmdli->cmd_args[0];
	return (ret);
}
