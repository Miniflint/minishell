#include "../../incs/minishell.h"

void	free_tab(char **ss)
{
	unsigned int	i;

	i = 0;
	if (!ss)
		return ;
	while (ss[i])
		free(ss[i++]);
	free(ss);
}
