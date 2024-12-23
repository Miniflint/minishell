#include "../../incs/minishell.h"

int	add_cmd(t_cmdli *cmdli, char *cmd)
{
	int	ret;

	ret = add_arg(cmdli, cmd);
	if (cmdli)
		cmdli->cmd = cmdli->cmd_args[0];
	return (ret);
}
