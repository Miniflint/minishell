/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:26:37 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:27:03 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	close_pipe(int *pipe)
{
	if (pipe)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
	return (0);
}

int	close_and_free(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close_pipe(cmdli->pipe_in);
	if (cmdli->cmd)
	{
		free(cmdli->cmd);
		cmdli->cmd = NULL;
	}
	if (cmdli->file_in)
	{
		free_tab(cmdli->file_in);
		cmdli->file_in = NULL;
	}
	if (cmdli->file_out)
	{
		free_file(cmdli->file_out);
		cmdli->file_out = NULL;
	}
	return (0);
}

int	exec_cmd(t_cmdli *cmdli)
{
	if (cmdli->pipe_out && cmdli->pipe_out[0] == -1
		&& cmdli->pipe_out[1] == -1)
		if (pipe(cmdli->pipe_out) == -1)
			return (return_error(errno, NULL));
	cmdli->cmd = get_absolute_path(cmdli->cmd, ft_get_var("PATH"));
	if (!cmdli->cmd)
		return (1);
	__update_env();
	cmdli->pid = fork();
	if (cmdli->pid == -1)
		return (return_error(errno, NULL));
	else if (!cmdli->pid)
	{
		set_redirection(cmdli);
		if (execve(cmdli->cmd, cmdli->cmd_args, ft_get_str_env()) == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s: #/r%s#0\n",
				cmdli->cmd_args[0], strerror(g_errno));
			exit(g_errno);
		}
	}
	return (close_and_free(cmdli));
}
