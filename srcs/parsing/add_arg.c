/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:04 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:26 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	add_arg(t_cmdli *cmdli, char *arg)
{
	char	**tmp;

	tmp = cmdli->cmd_args;
	cmdli->cmd_args = ft_strsjoin(arg, tmp);
	if (tmp)
		free(tmp);
	if (!cmdli->cmd_args)
		return (1);
	return (0);
}
