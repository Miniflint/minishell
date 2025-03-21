/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:39 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:14 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
