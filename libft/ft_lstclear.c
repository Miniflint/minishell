/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:31:22 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:31:23 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst)
	{
		while (*lst)
		{
			next_node = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = next_node;
		}
	}
}
