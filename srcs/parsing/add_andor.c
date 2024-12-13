#include "../../incs/minishell.h"

void	add_andor(t_cmdli **cmds_list, t_type *type, int and_or)
{
	*type = ANDOR;
	(*cmds_list)->next = create_cmdli();
	if (!(*cmds_list)->next)
		return (error_cmdli(cmds_list, "minishell: memory allocation failed\n"));
	(*cmds_list)->next->previous = (*cmds_list);
	*cmds_list = (*cmds_list)->next;
	(*cmds_list)->and_or = and_or;
}
