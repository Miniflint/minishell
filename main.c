#include "minishell.h"
#include "printfd/HEADER/ft_printfd.h"

int	g_errno;

void	add_new_tok(t_cmdli *cmdli, char *cursor, int *is_first, unsigned int len)
{
	if (cursor)
	{
		if (*is_first)
		{
			*is_first = 0;
			cmdli->tok_cursor->token = ft_strldup(cursor, len);
			if (!cmdli->tok_cursor->token)
				return ;
		}
		else
		{
			if (cmdli->tok_cursor->type == ARG
				|| cmdli->tok_cursor->type == CMD)
				new_unlist(cmdli, ft_strldup(cursor, len), ARG);
			else if (!cmdli->cmd_error)
			{
				cmdli->cmd_error = 1;
				ft_printfd(2, "#+minishell#0: %s:#/r ambigous redirect#0\n", cmdli->tok_cursor->token);
				g_errno = 1;
			}
		}
	}
}

void	split_tokens(t_cmdli *cmdli)
{
	int		is_first;
	char	*cursor;
	char	*tmp;
	int		i;
	char	quote;

	tmp = cmdli->tok_cursor->token;
	cursor = tmp;
	is_first = 1;
	i = 0;
	while(*cursor == ' ')
		++cursor;
	if (!*cursor)
	{
		if (tmp)
			free(tmp);
		cmdli->tok_cursor->token = ft_strdup("");
		if (!cmdli->tok_cursor->token)
			malloc_error(&cmdli);
		return ;
	}
	cmdli->tok_cursor->token = NULL;
	while (cursor[i])
	{
		while (cursor[i] && cursor[i] != ' ' && cursor[i] != '\'' && cursor[i] != '"')
			++i;
		if (cursor[i] == '\'' || cursor[i] == '"')
		{
			quote = cursor[i++];
			while (cursor[i] && cursor[i] != quote)
				++i;
			if (cursor[i])
				++i;
		}
		if (cursor[i] == ' ')
		{
			add_new_tok(cmdli, cursor, &is_first, i);
			cursor += i + 1;
			while(*cursor == ' ')
				++cursor;
			i = 0;
		}
	}
	if (i && cursor[i - 1] != ' ')
		add_new_tok(cmdli, cursor, &is_first, i);
	free(tmp);
}

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
		if (*s == '\'' || *s == '"')
			pass_until_char(&s, *s);
		else if (*s == '*')
			return (1);
		else
			++s;
	}
	return (0);
}

int	check_var(char *s)
{
	char	quote;

	quote = 0;
	while (*s)
	{
		if (*s == '"')
			quote = !quote;
		if (!quote && *s == '\'')
			pass_until_char(&s, '\'');
		else if (*s == '$' && (ft_isalnum(s[1]) || s[1] == '?'))
			return (1);
		else
			++s;
	}
	return (0);
}

char	*expend_home(t_cmdli *cmdli, int *i)
{
	char *ret;

	ret = cmdli->tok_cursor->token;
	if (*cmdli->tok_cursor->token == '~' && (!cmdli->tok_cursor->token[1] || cmdli->tok_cursor->token[1] == '/'))
	{
		++(*i);
		cmdli->tok_cursor->token = ft_get_var("HOME");
		if (!cmdli->tok_cursor->token)
			malloc_error(&cmdli);
	}
	else
		cmdli->tok_cursor->token = NULL;
	return (ret);
}

char	*ft_strljoin(char *s1, char *s2, int len)
{
	char	*str;
	char	*ret;
	int		i;

	str = malloc((ft_strlen(s1) + len + 1) * sizeof(char));
	ret = str;
	if (!str)
		return (0);
	i = 0;
	if (s1)
	{
		while (s1[i])
			*(str++) = s1[i++];
		free(s1);
	}
	i = 0;
	if (s2)
		while (i < len && *s2)
			str[i++] = *(s2++);
	str[i] = 0;
	return (ret);
}

char	*remove_quote(char *str)
{
	char	*ret;
	char	quote;
	int		offset;
	int		i;

	i = 0;
	quote = 0;
	offset = 0;
	while (str[i + offset])
	{
		if (quote && str[i + offset] == quote)
		{
			quote = 0;
			offset++;
		}
		else if (!quote && (str[i + offset] == '\'' || str[i + offset] == '\"'))
			quote = str[i + offset++];
		else
		{
			str[i] = str[i + offset];
			i++;
		}
	}
	str[i] = 0;
	if (!offset)
		return (str);
	ret = ft_strdup(str);
	free(str);
	if (!ret)
		malloc_error(get_cmdli(NULL));
	return (ret);
}

void	clean_tokens(t_cmdli *cmdli)
{
	t_unlist	*tmp;

	tmp = NULL;
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (!cmdli->tok_cursor->token || !*cmdli->tok_cursor->token)
		{
			if (tmp)
				tmp->next = cmdli->tok_cursor->next;
			else
				cmdli->tokens = cmdli->tokens->next;
			if (cmdli->tok_cursor->token)
				free(cmdli->tok_cursor->token);
			free(cmdli->tok_cursor);
			cmdli->tok_cursor = tmp;
		}
		else
			cmdli->tok_cursor->token = remove_quote(cmdli->tok_cursor->token);
		tmp = cmdli->tok_cursor;
		if (tmp)
			cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
}

void	expend(t_cmdli *cmdli)
{
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (check_var(cmdli->tok_cursor->token)
			|| (*cmdli->tok_cursor->token == '~' && (!cmdli->tok_cursor->token[1] || cmdli->tok_cursor->token[1] == '/')))
			(void)expend_var(cmdli);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (check_wildcard(cmdli->tok_cursor->token))
			check_open_dir(cmdli->tok_cursor->token, cmdli);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		split_tokens(cmdli);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	clean_tokens(cmdli);
}

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
			is_builtin(&cmdli_i, (cmdli_i->pipe_in || cmdli_i->pipe_out));
			sig_mode(0);
		}
		if (cmdli_i)
			cmdli_i = cmdli_i->next;
	}
}

void	execution(t_cmdli *cmdli, int status)
{
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
