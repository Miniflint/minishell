/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:36 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:36 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdli	**get_cmdli(t_cmdli **new_cmdli)
{
	static t_cmdli	**cmdli;

	if (new_cmdli)
		cmdli = new_cmdli;
	return (cmdli);
}
