/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:21 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:21 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_cat(char *prompt, const char *element, unsigned int *i)
{
	unsigned int	j;

	if (!prompt || !element)
		return ;
	j = 0;
	while (element[j])
		prompt[(*i)++] = element[j++];
}
