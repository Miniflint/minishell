#include "minishell.h"

void	offset_str(char *quote, int *offset, int *i, char *str)
{
	if (*quote && str[*i + *offset] == *quote)
	{
		*quote = 0;
		(*offset)++;
	}
	else if (!*quote && (str[*i + *offset] == '\''
			|| str[*i + *offset] == '\"'))
		*quote = str[*i + *offset++];
	else
	{
		str[*i] = str[*i + *offset];
		(*i)++;
	}
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
		offset_str(&quote, &offset, &i, str);
	str[i] = 0;
	if (!offset)
		return (str);
	ret = ft_strdup(str);
	free(str);
	if (!ret)
		malloc_error(get_cmdli(NULL));
	return (ret);
}
