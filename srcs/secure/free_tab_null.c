/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:40 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:12 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**free_tab_null(char **ss)
{
	unsigned int	i;

	i = 0;
	if (!ss)
		return (NULL);
	while (ss[i])
		free(ss[i++]);
	free(ss);
	return (NULL);
}
