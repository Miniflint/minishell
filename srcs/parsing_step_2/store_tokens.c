#include "../../incs/minishell.h"

int	store_tokens(t_cmdli *cmdli)
{
	// int	rd;
	int	ret;

	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		// rd = 0;
		// if (cmdli->tok_cursor->type == RDI || cmdli->tok_cursor->type == RDO
		// 	|| cmdli->tok_cursor->type == RDIH || cmdli->tok_cursor->type == RDOA)
		// 	rd = 1;
		// else
		// {	
			if (cmdli->tok_cursor->type == CMD)
				ret = add_cmd(cmdli, cmdli->tok_cursor->token);
			else if (cmdli->tok_cursor->type == ARG)
				ret = add_arg(cmdli, cmdli->tok_cursor->token);
			else
				ret = add_file(cmdli, cmdli->tok_cursor->token, cmdli->tok_cursor->type);
			if (ret)
				return (1);
		// }
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	free_unlist(cmdli);
	return (0);
}
