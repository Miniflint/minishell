#include "minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

int	g_errno; //Ne peux pas rester comme ca 

void	pass_until_char(char **s, char c)
{
	++*s;
	while (**s && **s != c)
		++*s;
	if (**s)
		++*s;
}

int	check_wildcard(char *s)
{
	while (*s)
	{
		if (*s == '*')
			return (1);
		else if (*s == '\'')
			pass_until_char(&s, '\'');
		else if (*s == '"')
			pass_until_char(&s, '"');
		++s;
	}
	return (0);
}

void	expend(t_cmdli *cmdli)
{
	cmdli->tok_cursor = cmdli->tokens;

	while (cmdli->tok_cursor)
	{
		if (check_wildcard(cmdli->tok_cursor->token))
			check_open_dir(".", cmdli->tok_cursor->token, cmdli);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
}

void	execution(t_cmdli *cmdli, int status)
{
	t_cmdli	*cmdli_i;

	cmdli_i = cmdli;
	while (cmdli_i)
	{
		sig_mode(1);
		expend(cmdli_i);
		store_tokens(cmdli_i);
		if (!cmdli_i->cmd)
			no_cmd(&cmdli_i);
		is_builtin(&cmdli_i, (cmdli_i->pipe_in || cmdli_i->pipe_out));
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
	shell->parenthesis = 0;
	shell->cmd_cmpt = 0;
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

	(void)av;
	status = 0;
	cmdli = NULL;
	ft_get_shell(&shell);
	init_shell(&shell, env);
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
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
