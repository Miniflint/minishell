#include "minishell.h"

static char	*strfreejoin(char *s1, char *s2)
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

static void	add_var_to_str(t_cmdli *cmdli, char **token, char **cursor, int *i)
{
	char	*tmp;

	if (*(*cursor) == '?')
	{
		*token = strfreejoin(*token, ft_get_var("?"));
		if (!*token)
			malloc_error(&cmdli);
		++(*cursor);
		*i = 0;
	}
	else
	{
		while (ft_isalnum((*cursor)[*i]))
			++(*i);
		tmp = ft_strldup((*cursor), (unsigned)(*i));
		if (!tmp)
			malloc_error(&cmdli);
		*token = strfreejoin(*token, ft_get_var(tmp));
		free(tmp);
		if (!*token)
			malloc_error(&cmdli);
		(*cursor) += *i;
		*i = 0;
	}
}

static void	in_quote(char *cursor, int *i)
{
	++(*i);
	while (cursor[*i] && cursor[*i] != '\'')
		++(*i);
	if (cursor[*i])
		++(*i);
}

static void	get_expend_value(char *quote, char **cursor, int *i, t_cmdli *cmdli)
{
	if (*quote && (*cursor)[*i] == *quote)
		*quote = 0;
	else if (!*quote && (*cursor)[*i] == '"')
		*quote = (*cursor)[*i];
	if ((*cursor)[*i] == '$'
		&& ((*cursor)[*i + 1] == '?' || ft_isalnum((*cursor)[*i + 1])))
	{
		cmdli->tok_cursor->token
			= ft_strljoin(cmdli->tok_cursor->token, (*cursor), *i);
		if (!cmdli->tok_cursor->token)
			malloc_error(&cmdli);
		(*cursor) += *i + 1;
		*i = 0;
		add_var_to_str(cmdli, &cmdli->tok_cursor->token, cursor, i);
	}
	else
		++(*i);
}

int	expend_var(t_cmdli *cmdli)
{
	char	*tmp;
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
			in_quote(cursor, &i);
		else
			get_expend_value(&quote, &cursor, &i, cmdli);
	}
	if (i)
		cmdli->tok_cursor->token
			= ft_strljoin(cmdli->tok_cursor->token, cursor, i);
	if (i && !cmdli->tok_cursor->token)
		malloc_error(&cmdli);
	if (tmp)
		free(tmp);
	return (0);
}
