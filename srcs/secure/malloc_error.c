#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	malloc_error(t_cmdli **cmdli)
{
	t_shell	*shell;
	char	**m_env;

	shell = ft_get_shell(NULL);
	if (shell)
	{
		if (shell->export)
			free_nodes_contents(&shell->export);
		if (shell->env)
			free_nodes(&shell->env);
		if (shell->read)
			free(shell->read);
	}
	m_env = ft_get_str_env();
	if (m_env)
		free_tab(m_env);
	free_cmdli(cmdli);
	clear_history();
	ft_printfd(2, "#+minishell#0:#/r memory allocation error#0\n");
	exit(1);
}
