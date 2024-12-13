#include "minishell.h"

t_shell	*ft_get_shell(t_shell *new_shell)
{
	static t_shell	*shell;

	if (new_shell)
		shell = new_shell;
	return (shell);
}
