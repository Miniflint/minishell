/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:06 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:06 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*ft_get_shell(t_shell *new_shell)
{
	static t_shell	*shell;

	if (new_shell)
		shell = new_shell;
	return (shell);
}
