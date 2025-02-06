#include "minishell.h"

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
					malloc_error(&cmdli);
				cursor += i + 1;
				i = 0;
				if (*cursor == '?')
				{

					cmdli->tok_cursor->token = strfreejoin(cmdli->tok_cursor->token, ft_get_var("?"));
					if (!cmdli->tok_cursor->token)
						malloc_error(&cmdli);
					++cursor;
					i = 0;
				}
				else
				{
					while (ft_isalnum(cursor[i]))
						++i;
					tmp2 = ft_strldup(cursor, (unsigned)i);
					if (!tmp2)
						malloc_error(&cmdli);
					cmdli->tok_cursor->token = strfreejoin(cmdli->tok_cursor->token, ft_get_var(tmp2));
					free(tmp2);
					if (!cmdli->tok_cursor->token)
						malloc_error(&cmdli);
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
			malloc_error(&cmdli);
	}
	if (tmp)
		free(tmp);
	return (0);
}
