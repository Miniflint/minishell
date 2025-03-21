/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:58 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:27:58 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable	*ft_get_env(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->env);
}
