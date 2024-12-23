#include "../../incs/minishell.h"

int	add_arg(t_cmdli *cmdli, char *arg)
{
	char	**tmp;

	tmp = cmdli->cmd_args;
	cmdli->cmd_args = ft_strsjoin(arg, tmp);
	if (tmp)
		free(tmp);
	if (!cmdli->cmd_args)
		return (1);
	return (0);
}
