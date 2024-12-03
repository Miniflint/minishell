/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:32:22 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 15:22:58 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	double_free(char **s1, char **s2)
{
	if (*s1)
		free(*s1);
	if (*s2)
		free(*s2);
	return (1);
}

int	heredoc(t_cmdli **cmdli, char *limit)
{
	char	*line;

	while (1)
	{
		line = readline("heredoc> ");
		if (line && ft_strcmp(line, limit))
		{
			if (write((*cmdli)->pipe_in[1], line, ft_strlen(line)) == -1
				|| write((*cmdli)->pipe_in[1], "\n", 1) == -1)
				return (double_free(&line, &limit));
			free(line);
		}
		else
		{
			if (line)
				free(line);
			break ;
		}
	}
	close((*cmdli)->pipe_in[1]);
	free(limit);
	exit(0);
}

void	heredoc_parent(t_cmdli **cmdli, pid_t pid, char *limit)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	sig_mode(1);
	if (WIFEXITED(status))
		g_errno = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_errno = write(1, "\n", 1);
	free(limit);
	if (g_errno)
		return (free_cmdli(cmdli));
}

void	heredoc_child(t_cmdli **cmdli, char *limit)
{
	sig_mode(3);
	close((*cmdli)->pipe_in[0]);
	if (heredoc(cmdli, limit))
	{
		close((*cmdli)->pipe_in[1]);
		exit_error(errno, NULL);
	}
}

void	write_heredoc(t_cmdli **cmdli, char *limit)
{
	pid_t	pid;

	(*cmdli)->here_doc = 1;
	if (!(*cmdli)->pipe_in)
	{
		(*cmdli)->pipe_in = malloc(2 * sizeof(int));
		if (!(*cmdli)->pipe_in)
			return (error_cmdli(cmdli, "memory allocation failed"));
	}
	if (pipe((*cmdli)->pipe_in) == -1)
		return (error_cmdli(cmdli, strerror(errno)));
	sig_mode(0);
	pid = fork();
	if (pid == -1)
		return (error_cmdli(cmdli, strerror(errno)));
	else if (!pid)
		heredoc_child(cmdli, limit);
	else
		heredoc_parent(cmdli, pid, limit);
}
