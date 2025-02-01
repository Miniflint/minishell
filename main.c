#include "minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

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
			ft_printfd(2, "malloc error %d %s", __LINE__, __FILE__);
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
	while (*s)
	{
		if (*s == '\'')
			pass_until_char(&s, '\'');
		else if (*s == '$' && (ft_isalnum(s[1]) || s[1] == '?'))
			return (1);
		else
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

char	*expend_home(t_cmdli *cmdli, int *i)
{
	char *ret;

	ret = cmdli->tok_cursor->token;
	if (*cmdli->tok_cursor->token == '~' && (!cmdli->tok_cursor->token[1] || cmdli->tok_cursor->token[1] == '/'))
	{
		++(*i);
		cmdli->tok_cursor->token = ft_get_var("HOME");
		if (!cmdli->tok_cursor->token)
		{
			ft_printfd(2, "Erreur de malloc non gerer dans main.c ligne 40\n");
			return (NULL);
		}
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

char	*strfreejoin(char *s1, char *s2)
{
	char	*str;
	char	*ret;
	char	*tmp;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ret = str;
	if (!str)
		return (0);
	if (s1)
	{
		tmp = s1;
		while (*s1)
			*(str++) = *(s1++);
		free(tmp);
	}
	if (s2)
	{
		tmp = s2;
		while (*s2)
			*(str++) = *(s2++);
		free(tmp);
	}
	*str = 0;
	return (ret);
}


int	expend_var(t_cmdli *cmdli)
{
 	char	*tmp;
	char	*tmp2;
	int		i;
	char	*cursor;
	char	quote;

	i = 0;
	tmp = expend_home(cmdli, &i);
	cursor = tmp + i;
	i = 0;
	quote = 0;
	while (cursor[i])
	{
		if (!quote && cursor[i] == '\'')
		{
			++i;
			while (cursor[i] && cursor[i] != '\'')
				++i;
			if (cursor[i])
				++i;
		}
		else
		{
			if (quote && cursor[i] == quote)
				quote = 0;
			else if (!quote && cursor[i] == '"')
				quote = cursor[i];
			if (cursor[i] == '$' && (cursor[i + 1] == '?' || ft_isalnum(cursor[i + 1])))
			{
				cmdli->tok_cursor->token = ft_strljoin(cmdli->tok_cursor->token, cursor, i);
				if (!cmdli->tok_cursor->token)
					return (ft_printfd(2, "Fais chier... Ligne %d %s\n", __LINE__, __FILE__));
				cursor += i + 1;
				i = 0;
				if (*cursor == '?')
				{

					cmdli->tok_cursor->token = strfreejoin(cmdli->tok_cursor->token, ft_get_var("?"));
					if (!cmdli->tok_cursor->token)
						return (ft_printfd(2, "Fais chier... Ligne %d %s\n", __LINE__, __FILE__));
					++cursor;
					i = 0;
				}
				else
				{
					while (ft_isalnum(cursor[i]))
						++i;
					tmp2 = ft_strldup(cursor, (unsigned)i);
					if (!tmp2)
						return (ft_printfd(2, "Fais chier... Ligne %d %s\n", __LINE__, __FILE__));
					cmdli->tok_cursor->token = strfreejoin(cmdli->tok_cursor->token, ft_get_var(tmp2));
					free(tmp2);
					if (!cmdli->tok_cursor->token)
						return (ft_printfd(2, "Fais chier... Ligne %d %s\n", __LINE__, __FILE__));
					cursor += i;
					i = 0;
				}
			}
			else
				++i;
		}
	}
	if (i)
	{
		cmdli->tok_cursor->token = ft_strljoin(cmdli->tok_cursor->token, cursor, i);
		if (!cmdli->tok_cursor->token)
			return (ft_printfd(2, "Fais chier... Ligne %d %s\n", __LINE__, __FILE__));
	}
	if (tmp)
		free(tmp);
	return (0);
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
	return (ret);
}

void	expend(t_cmdli *cmdli)
{
	t_unlist	*tmp;

	tmp = NULL;
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
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (!cmdli->tok_cursor->token || !*cmdli->tok_cursor->token)
		{
			if (tmp)
				tmp->next = cmdli->tok_cursor->next;
			else
				cmdli->tokens = cmdli->tokens->next;
			if (!*cmdli->tok_cursor->token)
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

void	execution(t_cmdli *cmdli, int status)
{
	t_cmdli	*cmdli_i;

	cmdli_i = cmdli;
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
