#include "minishell.h"

char	**ft_get_str_env(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->str_env);
}
