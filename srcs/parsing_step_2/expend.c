#include "minishell.h"

char	*expend_home(t_cmdli *cmdli, int *i)
{
	char	*ret;

	ret = cmdli->tok_cursor->token;
	if (*cmdli->tok_cursor->token == '~'
		&& (!cmdli->tok_cursor->token[1] || cmdli->tok_cursor->token[1] == '/'))
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

void	expend(t_cmdli *cmdli)
{
	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (check_var(cmdli->tok_cursor->token)
			|| (*cmdli->tok_cursor->token == '~'
				&& (!cmdli->tok_cursor->token[1]
					|| cmdli->tok_cursor->token[1] == '/')))
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
