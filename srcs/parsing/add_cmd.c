#include "../../incs/minishell.h"

void	add_cmd(t_cmdli **cmds_list, char *cmd, t_type *type)
{
	add_arg(cmds_list, cmd, type);
	*type = CMD;
	if (*cmds_list)
		(*cmds_list)->cmd = (*cmds_list)->cmd_args[0];
}
