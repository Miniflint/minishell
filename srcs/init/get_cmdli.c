#include "minishell.h"

t_cmdli	**get_cmdli(t_cmdli **new_cmdli)
{
	static t_cmdli	**cmdli;

	if (new_cmdli)
		cmdli = new_cmdli;
	return (cmdli);
}
