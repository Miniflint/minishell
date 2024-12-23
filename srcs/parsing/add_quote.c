#include "../../incs/minishell.h"

char	*add_quote(char **cmdline, char *str, unsigned int *i)
{
	char			*ret;
	unsigned int	j;
	char			*tmp;
	char			*new;

	ret = NULL;
	j = 1;
	while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != '\'')
		j++;
	tmp = str;
	new = ft_substr((*cmdline), *i, ++j);
	if (!new)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	ret = ft_strjoin(str, new);
	free(new);
	if (tmp)
		free(tmp);
	if (ret)
		*i += j;
	return (ret);
}
