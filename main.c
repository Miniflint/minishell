/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:54 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 15:25:09 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

void	execution(t_cmdli *cmdli, int status)
{
	t_cmdli	*cmdli_i;

	cmdli_i = cmdli;
	while (cmdli_i)
	{
		sig_mode(1);
		if (!cmdli_i->cmd)
			no_cmd(&cmdli_i);
		else if (cmdli_i->pipe_in || cmdli_i->pipe_out)
			is_builtin(&cmdli_i, 1);
		else
			is_builtin(&cmdli_i, 0);
		sig_mode(0);
		if (cmdli_i)
			cmdli_i = cmdli_i->next;
	}
	while (wait(&status) != -1)
		if (WIFEXITED(status))
			g_errno = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_errno = WTERMSIG(status) + 128;
	if (WIFSIGNALED(status))
		write(1, "\n", 1);
	sig_mode(1);
	free_cmdli(&cmdli);
}

void	ft_say_check(int ac, t_shell *shell)
{
	if (ac > 1)
		shell->say = 1;
	else
		shell->say = 0;
}

void	parsing(t_shell *shell, t_cmdli *cmdli, int status)
{
	if (shell->read[0])
		add_history(shell->read);
	cmdli = get_cmds(&shell->read);
	if (cmdli)
		execution(cmdli, status);
	free(shell->read);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	t_cmdli	*cmdli;
	int		status;

	status = 0;
	cmdli = NULL;
	ft_get_shell(&shell);
	init_shell(&shell, env);
	ft_say_check(ac, &shell);
	print_minishell();
	(void)av;
	term_handler();
	signal(SIGQUIT, SIG_IGN);
	sig_mode(1);
	while (true)
	{
		shell.read = readline(ft_prompt());
		if (shell.read)
			parsing(&shell, cmdli, status);
		else
			ft_sig_exit();
	}
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
