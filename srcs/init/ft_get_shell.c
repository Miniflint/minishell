/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:27:27 by hrolle            #+#    #+#             */
/*   Updated: 2024/12/06 17:41:54 by trgoel           ###   ########.fr       */
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
