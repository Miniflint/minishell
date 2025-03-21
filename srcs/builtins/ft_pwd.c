/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:34 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:27:35 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
