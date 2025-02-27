#include "minishell.h"
#include "../printfd/HEADER/ft_printfd.h"

void	view_cmdli(t_cmdli *cmdli)
{
	t_unlist	*tokens;

	while (cmdli)
	{
		tokens = cmdli->tokens;
		ft_printfd(1, "Tokens :\n");
		while (tokens)
		{
			ft_printfd(1, " - %s\n", tokens->token);
			tokens = tokens->next;
		}
		ft_printfd(1, "Andor    : %d\n", cmdli->and_or);
		ft_printfd(1, "Pipe out : %p\n", cmdli->pipe_out);
		ft_printfd(1, "P in     : %d\n", cmdli->create_fork);
		ft_printfd(1, "P out    : %d\n", cmdli->exit_fork);
		cmdli = cmdli->next;
	}
}
