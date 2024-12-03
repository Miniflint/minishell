/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:15 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/02 20:02:02 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	close_and_free_builtin(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close_pipe(cmdli->pipe_in);
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

int	builtin_fork(void (*f)(t_cmdli **), t_cmdli **cmdli)
{
	(*cmdli)->pid = fork();
	if ((*cmdli)->pid == -1)
		return (return_error(errno, NULL));
	else if (!(*cmdli)->pid)
	{
		set_redirection((*cmdli));
		(*cmdli)->fd_out = STDOUT_FILENO;
		f(cmdli);
		exit (g_errno);
	}
	return (close_and_free_builtin((*cmdli)));
}

void	exec_builtin(void (*f)(t_cmdli **), t_cmdli **cmdli, int mode)
{
	if ((*cmdli)->pipe_out && (*cmdli)->pipe_out[0] == -1
		&& (*cmdli)->pipe_out[1] == -1)
		if (pipe((*cmdli)->pipe_out) == -1)
			return (void_error(errno, NULL));
	if (mode)
	{
		sig_mode(3);
		builtin_fork(f, cmdli);
		sig_mode(0);
	}
	else
	{
		if (!builtin_set_file(*cmdli))
			f(cmdli);
		if ((*cmdli)->fd_out != -1 && (*cmdli)->fd_out != 1)
			close((*cmdli)->fd_out);
		if ((*cmdli)->fd_in != -1)
			close((*cmdli)->fd_in);
	}
}

void	is_builtin(t_cmdli **cmdli, int mode)
{
	if (andor_check(cmdli))
		return ;
	if (!ft_strcmp((*cmdli)->cmd, "env"))
		exec_builtin(ft_env, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd_args[0], "export"))
		exec_builtin(ft_export, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd, "unset"))
		exec_builtin(ft_unset, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd, "pwd"))
		exec_builtin(ft_pwd, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd, "echo"))
		exec_builtin(ft_echo, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd, "cd"))
		exec_builtin(ft_cd, cmdli, mode);
	else if (!ft_strcmp((*cmdli)->cmd, "exit")
		|| !ft_strcmp((*cmdli)->cmd, "bye"))
		exec_builtin(ft_exit, cmdli, mode);
	else
	{
		sig_mode(1);
		exec_cmd(*cmdli);
		sig_mode(0);
	}
}

/*
	check if cmd->cmd is a builtin
	returns 0 : if cmd->cmd is empty or if it's not a builtin
	returns 1 : if cmd->cmd matches with builtin
*/
// int	is_builtin(t_cmdli *cmdli)
// {
// 	const char	*builtins[]
// 		= {"echo", "cd", "pwd", "env", "export", "unset", "exit", NULL};
// 	int			i;

// 	if (!cmdli || !cmdli->cmd)
// 		return (0);
// 	i = 0;
// 	while (builtins[i])
// 	{
// 		if (!ft_strcmp(builtins[i], cmdli->cmd))
// 			return (1);
// 		++i;
// 	}
// 	return (0);
// }

// int	run_builtin(const char *str, t_cmdli *cmd, t_shell *shell, int len)
// {
// 	cmd->pid = fork();
// 	if (cmd->pid == -1)
// 	{
// 		g_errno = errno;
// 		ft_printfd(2, "#+wminishell#0:#/r %s#0\n", strerror(g_errno));
// 		return (g_errno);
// 	}
// 	else if (!cmd->pid)
// 	{
// 		set_redirection(cmd);
// 		if (ft_strncmp(str, "env", len))
// 			ft_env(shell);
// 		else if (ft_strncmp(str, "export", len))
// 			ft_export(shell, cmd);
// 		else if (ft_strncmp(str, "pwd", len))
// 			ft_pwd();
// 		if (!ft_strncmp(str, "echo", len))
// 			ft_echo(&cmd->cmd_args[1]);
// 		if (!ft_strncmp(str, "cd", len))
// 			ft_cd(cmd->cmd_args);
// 		exit(0);
// 	}
// 	else
// 		return (close_pipe(cmd->pipe_in) + 1);
// 	return (1);
// }
