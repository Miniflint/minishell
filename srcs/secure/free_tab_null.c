#include "minishell.h"

char	**free_tab_null(char **ss)
{
	unsigned int	i;

	i = 0;
	if (!ss)
		return (NULL);
	while (ss[i])
		free(ss[i++]);
	free(ss);
	return (NULL);
}
