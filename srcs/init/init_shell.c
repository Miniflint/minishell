/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:17 by lgenevey          #+#    #+#             */
/*   Updated: 2024/12/06 17:42:37 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell, char **m_env)
{
	shell->env = init_env(m_env);
	shell->export = init_export();
	shell->str_env = m_env;
	shell->if_sig = 1;
}
