#include "../../incs/minishell.h"

t_cmdli	*create_cmdli(void)
{
	t_cmdli	*ret;

	ret = malloc(1 * sizeof(t_cmdli));
	if (!ret)
		return (NULL);
	*ret = (t_cmdli){};
	ret->fd_in = -1;
	ret->fd_out = -1;
	return (ret);
}
