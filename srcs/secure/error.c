#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	return_error(int error, char *custom)
{
	g_errno = error;
	if (custom)
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", custom);
	else
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(error));
	return (error);
}

int	exit_error(int error, char *custom)
{
	g_errno = error;
	if (custom)
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", custom);
	else
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(error));
	exit(error);
}

char	**ss_error(int error, char *custom)
{
	g_errno = error;
	if (custom)
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", custom);
	else
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(error));
	return (NULL);
}

char	*s_error(int error, char *custom)
{
	g_errno = error;
	if (custom)
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", custom);
	else
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(error));
	return (NULL);
}

void	void_error(int error, char *custom)
{
	g_errno = error;
	if (custom)
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", custom);
	else
		ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(error));
}
