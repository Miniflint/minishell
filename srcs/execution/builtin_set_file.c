#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	builtin_set_file(t_cmdli *cmdli)
{
	if (cmdli->file_out)
	{
		if (set_file_out(cmdli))
			return (1);
	}
	else
		cmdli->fd_out = 1;
	if (cmdli->file_in)
		if (set_file_in(cmdli))
			return (1);
	return (0);
}
