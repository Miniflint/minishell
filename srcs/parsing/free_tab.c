#include "../../incs/minishell.h"

void	free_tab(char **ss)
{
	unsigned int	i;

	if (!ss)
		return ;
	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		ss[i] = NULL;
		i++;
	}
	free(ss);
	ss = NULL;
}
