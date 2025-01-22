#include "minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

int	g_errno;

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
		if (*s == '\'')
			pass_until_char(&s, '\'');
		else if (*s == '"')
			pass_until_char(&s, '"');
		if (*s == '*')
			return (1);
		++s;
	}
	return (0);
}

int	expend_dquote_var(char **ret, char *str)
{
	if (ret)
		ft_printfd(1, "I'm in expend_dquote_var with %s\n", str);
	return (0);
}

void	expend_var(t_cmdli *cmdli)
{
	char	*ret;
	int		i;

	ret = NULL;
	if (*cmdli->tok_cursor->token == '~' && (!cmdli->tok_cursor->token[1] || cmdli->tok_cursor->token[1] == '/'))
	{
		ret = ft_strjoin(ft_get_var("HOME"), cmdli->tok_cursor->token + 1);
		if (!ret)
		{
			ft_printfd(2, "Erreur de malloc non gerer dans main.c ligne 40\n");
			return ;
		}
		free(cmdli->tok_cursor->token);
		cmdli->tok_cursor->token = ret;
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	while (cmdli->tok_cursor)
	{
		i = 0;
		while (cmdli->tok_cursor->token[i])
		{
			if (cmdli->tok_cursor->token[i] == '"')
			{
				if (expend_dquote_var(&ret, cmdli->tok_cursor->token + i + 1))
					return ;
			}
			++i;
		}
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
}

char	*ft_strljoin(char *s1, char *s2, int size)
{
	int	i;
	int	j;
	char	*new_str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (len < size)
		size = len;
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] && i < size)
			new_str[i] = s1[i];
	j = -1;
	if (s2)
		while (s2[++j] && (i + j) < size)
			new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
}

void	expend(t_cmdli *cmdli)
{
	// cmdli->tok_cursor = cmdli->tokens;
	// while (cmdli->tok_cursor)
	// {
	// 	expend_var(cmdli);
	// 	cmdli->tok_cursor = cmdli->tok_cursor->next;
	// }
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (check_wildcard(cmdli->tok_cursor->token))
			check_open_dir(cmdli->tok_cursor->token, cmdli);
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
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	t_cmdli	*cmdli;
	int		status;

	(void)av;
	status = 0;
	cmdli = NULL;
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
	free_tab(shell.str_env);
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
