/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:40:46 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/26 02:18:06 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
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
