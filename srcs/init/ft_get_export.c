#include "minishell.h"

t_variable	*ft_get_export(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->export);
}
