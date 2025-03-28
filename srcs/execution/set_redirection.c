/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:26:53 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:26:57 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	set_file_in(t_cmdli *cmdli)
{
	unsigned int	i;

	i = 0;
	while (cmdli->file_in[i])
	{
		if (cmdli->fd_in != -1)
			close(cmdli->fd_in);
		cmdli->fd_in = open(cmdli->file_in[i++], O_RDONLY);
		if (cmdli->fd_in == -1)
		{
			g_errno = 1;
			ft_printfd(2, "#+wminishell#0: %s:#/r %s#0\n",
				cmdli->file_in[i - 1], strerror(errno));
			return (1);
		}
	}
	return (0);
}

int	set_file_out(t_cmdli *cmdli)
{
	unsigned int	i;

	i = 0;
	while (cmdli->file_out[i])
	{
		if (cmdli->fd_out != -1)
			close(cmdli->fd_out);
		if (cmdli->file_out[i]->type == RDO)
			cmdli->fd_out = open(cmdli->file_out[i++]->name,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (cmdli->file_out[i]->type == RDOA)
			cmdli->fd_out = open(cmdli->file_out[i++]->name,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmdli->fd_out == -1)
		{
			g_errno = 1;
			ft_printfd(2, "#+wminishell#0: %s:#/r %s#0\n",
				cmdli->file_out[i - 1], strerror(errno));
			return (1);
		}
	}
	return (0);
}

void	set_in(t_cmdli *cmdli)
{
	if (cmdli->file_in && cmdli->fd_in != -1 && !cmdli->here_doc)
	{
		dup2(cmdli->fd_in, STDIN_FILENO);
		close(cmdli->fd_in);
		if (cmdli->pipe_in)
			close(cmdli->pipe_in[0]);
	}
	else if (cmdli->pipe_in)
	{
		dup2(cmdli->pipe_in[0], STDIN_FILENO);
		close(cmdli->pipe_in[0]);
	}
}

void	set_out(t_cmdli *cmdli)
{
	if (cmdli->fd_out != -1)
	{
		dup2(cmdli->fd_out, STDOUT_FILENO);
		close(cmdli->fd_out);
		if (cmdli->pipe_out)
			close(cmdli->pipe_out[1]);
	}
	else if (cmdli->pipe_out)
	{
		dup2(cmdli->pipe_out[1], STDOUT_FILENO);
		close(cmdli->pipe_out[1]);
	}
}

void	set_redirection(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close(cmdli->pipe_in[1]);
	if (cmdli->pipe_out)
		close(cmdli->pipe_out[0]);
	if (cmdli->file_out)
		if (set_file_out(cmdli))
			exit(g_errno);
	if (cmdli->file_in)
		if (set_file_in(cmdli))
			exit(g_errno);
	set_in(cmdli);
	set_out(cmdli);
}
