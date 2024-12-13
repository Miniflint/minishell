#include "minishell.h"

t_variable	*ft_get_env(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->env);
}