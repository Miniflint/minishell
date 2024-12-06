/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:50 by hrolle            #+#    #+#             */
/*   Updated: 2024/12/06 17:40:42 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	no_cmd(t_cmdli **cmdli)
{
	if (andor_check(cmdli))
		return (0);
	if ((*cmdli)->pipe_out && (*cmdli)->pipe_out[0] == -1
		&& (*cmdli)->pipe_out[1] == -1)
		if (pipe((*cmdli)->pipe_out) == -1)
			return (return_error(errno, NULL));
	(*cmdli)->pid = fork();
	if ((*cmdli)->pid == -1)
		return (return_error(errno, NULL));
	else if (!(*cmdli)->pid)
	{
		set_redirection((*cmdli));
		exit (0);
	}
	return (close_and_free((*cmdli)));
}
