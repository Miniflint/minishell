/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:13 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:13 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Our getenv function
*/
char	*ft_get_var(char *substr)
{
	t_variable	*env;

	env = ft_get_shell(NULL)->env;
	if (!env || !substr)
		return (ft_strdup(""));
	if (!ft_strcmp(substr, "?"))
		return (ft_itoa(g_errno));
	while (env)
	{
		if (!ft_strcmp(env->name, substr))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}
