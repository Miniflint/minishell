/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:27 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:18 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_tab(char **ss)
{
	unsigned int	i;

	if (!ss)
		return ;
	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		ss[i] = NULL;
		i++;
	}
	free(ss);
	ss = NULL;
}
