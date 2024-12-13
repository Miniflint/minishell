#include "../../incs/minishell.h"

t_cmdli	*cmdli_first(t_cmdli *cmds_list)
{
	if (!cmds_list)
		return (NULL);
	while (cmds_list->previous)
		cmds_list = cmds_list->previous;
	return (cmds_list);
}
