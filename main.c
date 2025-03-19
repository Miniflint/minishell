#include "minishell.h"
#include "printfd/HEADER/ft_printfd.h"

int	g_errno;

void	execution_while(t_cmdli *cmdli_i)
{
	while (cmdli_i)
	{
		expend(cmdli_i);
		if (cmdli_i->tokens)
		{
			store_tokens(cmdli_i);
			sig_mode(1);
			if (!cmdli_i->cmd)
				no_cmd(&cmdli_i);
			else
				is_builtin(&cmdli_i, (cmdli_i->pipe_in || cmdli_i->pipe_out));
			sig_mode(0);
		}
		if (cmdli_i)
			cmdli_i = cmdli_i->next;
	}
}

void	edit_p_lvl(t_cmdli *cmdli)
{
	int	new_lvl;

	new_lvl = 0;
	while (cmdli)
	{
		new_lvl += cmdli->create_fork;
		cmdli->p_lvl = new_lvl;
		new_lvl -= cmdli->exit_fork;
		cmdli = cmdli->next;
	}
}

void	execution(t_cmdli *cmdli, int status)
{
	edit_p_lvl(cmdli);
	view_cmdli(cmdli);//temp
	execution_while(cmdli);
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
	shell->say = ac > 1;
}

void	parsing(t_shell *shell, t_cmdli *cmdli, int status)
{
	if (shell->read[0])
		add_history(shell->read);
	shell->parenthesis = 0;
	shell->cmd_cmpt = 0;
	cmdli = get_cmds(&shell->read);
	if (cmdli)
		execution(cmdli, status);
	free(shell->read);
	shell->read = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	t_cmdli	*cmdli;
	int		status;

	(void)av;
	status = 0;
	cmdli = NULL;
	init_shell(&shell, &cmdli, env);
	ft_say_check(ac, &shell);
	//print_minishell();
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
	free_tab(shell.str_env);
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
