/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_3_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:17 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:27:37 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_3_a(void)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "     #w██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ██#r█#w     ██████#r█#w    ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ████████#r█#w   ██#r█#w         ██#r█#w      \n  ");
	ft_printfd(1, "   ███#r█#w    ███#r█#w   ██#r█#w   ███#r█#w  ██#r█");
	ft_printfd(1, "#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w      ");
	ft_printfd(1, "\n     ████#r█#w  ████#r█#w   ██#r█#w   ████#r█#w ██");
	ft_printfd(1, "#r█#w   ██#r█#w   ███#r█#w         ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ██#r█#w         ██#r█#w         ██#r█#w      \n  ");
}

void	image_3(int back)
{
	image_3_a();
	ft_printfd(1, "   ██#r█#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ██#r█#w█");
	ft_printfd(1, "█#r█#w██#r█#w   ██#r█#w     █████#r█#w     ████████");
	ft_printfd(1, "#r█#w   ██████      ██#r█#w         ██#r█#w      \n  ");
	ft_printfd(1, "   ██#r█#w ███#r█#w ██#r█#w   ██#r█#w   ██#r█#w ████");
	ft_printfd(1, "#r█#w   ██#r█#w         ███#r█#w   ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ██#r█#w         ██#r█#w         ██#r█#w      \n  ");
	ft_printfd(1, "   ██#r█#w  █#r█#w  ██#r█#w   ██#r█#w   ██#r█#w  ███");
	ft_printfd(1, "#r█#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w  ");
	ft_printfd(1, "    \n     ██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w ");
	ft_printfd(1, "  ██#r█#w   ██#r█#w    ██████#r█#w     ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ████████#r█#w   ████████#r█#w   ████████#r█#w");
	ft_printfd(1, "\n                                                  ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "\n");
	if (back)
		back_to_the_future();
}

void	image_4_a(void)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████");
	ft_printfd(1, "#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█");
	ft_printfd(1, "#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█");
	ft_printfd(1, "#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   ");
	ft_printfd(1, "#b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w");
	ft_printfd(1, "        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    ");
	ft_printfd(1, "    #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█");
	ft_printfd(1, "#w██#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w██");
	ft_printfd(1, "#p█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w█████#r█#w");
	ft_printfd(1, "    #b█#w████████#r█#w  #b█#w██████     #b█#w██#r█#w");
}

void	image_4(int back)
{
	image_4_a();
	ft_printfd(1, "        #b█#w██#r█#w      \n    #b█#w██#r█#w#b█#w███");
	ft_printfd(1, "#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w██");
	ft_printfd(1, "██#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w");
	ft_printfd(1, "        #b█#w██#r█#w      \n    #b█#w██#r█#w #b█#w█");
	ft_printfd(1, "#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w█");
	ft_printfd(1, "██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  ");
	ft_printfd(1, "#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█");
	ft_printfd(1, "#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    ");
	ft_printfd(1, "#b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█");
	ft_printfd(1, "#w████████#r█#w  #b█#w████████#r█#w\n                ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                  \n");
	if (back)
		back_to_the_future();
}
