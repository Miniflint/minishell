/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/29 17:45:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	Displays env variables
	The order we see is when items are created
*/
void	ft_env(t_cmdli **cmdli)
{
	t_variable	*env;

	g_errno = 0;
	env = ft_get_env();
	if (!env)
		return ;
	while (env)
	{
		if (!env->value)
			ft_printfd((*cmdli)->fd_out, "%s\n", env->name);
		else
			ft_printfd((*cmdli)->fd_out, "%s=%s\n", env->name, env->value);
		env = env->next;
	}
}
