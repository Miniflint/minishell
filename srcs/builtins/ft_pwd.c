#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

// getcwd : Get the name of the current working directory
void	ft_pwd(t_cmdli **cmdli)
{
	char	*cwd;
	char	buff[PATH_MAX];

	cwd = getcwd(buff, PATH_MAX);
	if (cwd != NULL)
		ft_printfd((*cmdli)->fd_out, "%s\n", cwd);
	g_errno = 0;
}
