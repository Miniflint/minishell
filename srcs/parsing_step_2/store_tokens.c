#include "../../incs/minishell.h"

static char	*get_and_set_token(t_cmdli	*cmdli)
{
	char	*ret;

	ret = cmdli->tok_cursor->token;
	cmdli->tok_cursor->token = NULL;
	return (ret);
}

int	store_tokens(t_cmdli *cmdli)
{
	int		ret;

	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		if (cmdli->tok_cursor->type == CMD)
			ret = add_cmd(cmdli, get_and_set_token(cmdli));
		else if (cmdli->tok_cursor->type == ARG)
			ret = add_arg(cmdli, get_and_set_token(cmdli));
		else
			ret = add_file(cmdli, get_and_set_token(cmdli), cmdli->tok_cursor->type);
		if (ret)
			return (1);
		cmdli->tok_cursor = cmdli->tok_cursor->next;
	}
	free_unlist(cmdli);
	return (0);
}
