#include "minishell.h"

int	check_next_andor(t_cmdli **cmdli, int new_errno)
{
	if ((*cmdli)->next && ((new_errno && (*cmdli)->next->and_or == 1)
	|| (!new_errno && (*cmdli)->next->and_or == 2)))
	{
		(*cmdli)->previous = (*cmdli);
		(*cmdli) = (*cmdli)->next;
		return (0);
	}
	return (1);
}

int	andor_while_check(t_cmdli **cmdli, int new_errno)
{
	while ((*cmdli) && ((new_errno && (*cmdli)->and_or == 1)
		|| (!new_errno && (*cmdli)->and_or == 2)))
	{
		if ((*cmdli)->pipe_in && (*cmdli)->pipe_in[0] == -1
			&& (*cmdli)->pipe_in[0] == -1)
			close_pipe((*cmdli)->pipe_in);
		if (check_next_andor(cmdli, new_errno))
			return (1);
		while ((*cmdli) && !(*cmdli)->and_or)
		{
			if ((*cmdli)->pipe_in && (*cmdli)->pipe_in[0] == -1
				&& (*cmdli)->pipe_in[0] == -1)
				close_pipe((*cmdli)->pipe_in);
			if (check_next_andor(cmdli, new_errno))
				return (1);
		}
	}
	if (!(*cmdli))
		return (1);
	return (0);
}

int	andor_check(t_cmdli **cmdli)
{
	int	status;
	int	tmp_errno;

	status = 0;
	tmp_errno = g_errno;
	if (!(*cmdli)->and_or)
		return (0);
	sig_mode(0);
	while (wait(&status) != -1)
		if (WIFEXITED(status))
			g_errno = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_errno = WTERMSIG(status) + 128;
	if (status && WIFSIGNALED(status))
		write(1, "\n", 1);
	sig_mode(1);
	if (g_errno)
		tmp_errno = g_errno;
	if (andor_while_check(cmdli, tmp_errno))
		return (1);
	return (0);
}
