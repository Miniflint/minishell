/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:26:51 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:26:58 by trgoel           ###   ########.fr       */
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
