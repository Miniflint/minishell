/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:02 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:02 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable	*ft_get_export(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->export);
}
