/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_5_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:18 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:27:34 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_5_a(void)
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
	ft_printfd(1, "    #b█#w██#r█#w        #b█#w██#r█#w      \n  #b▀#w▀");
	ft_printfd(1, "▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w  #b▀#w▀▀#p▀#w▀");
	ft_printfd(1, "▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    #b▀#w▀▀▀▀▀#r▀#w    #b");
	ft_printfd(1, "▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r▀#w    #b▀#w▀▀#r▀#w  ");
	ft_printfd(1, "      #b▀#w▀▀#r▀#w      \n    #b█#w██#r█#w#b█#w███#r");
}

void	image_5(int back)
{
	image_5_a();
	ft_printfd(1, "█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w  ");
	ft_printfd(1, "      #b█#w██#r█#w      \n    #b█#w██#r█#w #b█#w█#r█");
	ft_printfd(1, "#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b");
	ft_printfd(1, "█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w");
	ft_printfd(1, "  #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█#w█");
	ft_printfd(1, "█#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b");
	ft_printfd(1, "█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w█");
	ft_printfd(1, "███████#r█#w  #b█#w████████#r█#w\n                  ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                \n");
	if (back)
		back_to_the_future();
}

void	image_6_a(void)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "        #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██");
	ft_printfd(1, "████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███████");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n    ");
	ft_printfd(1, "   #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r");
	ft_printfd(1, "█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w ");
	ft_printfd(1, "     \n      #b█#w████#r█#w #b█#w████#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      ");
	ft_printfd(1, "\n       #b▄#w▄▄#p▄#w▄▄▄▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w ");
	ft_printfd(1, " #b▄#w▄▄#p▄#w▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w    #b▄#w▄▄");
	ft_printfd(1, "▄▄▄#r▄#w    #b▄#w▄▄▄▄▄▄▄▄#r▄#w  #b▄#w▄▄▄▄▄▄#r▄#w    ");
}

void	image_6(int back)
{
	image_6_a();
	ft_printfd(1, "#b▄#w▄▄#r▄#w        #b▄#w▄▄#r▄#w      \n      #b█#w█");
	ft_printfd(1, "█#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w");
	ft_printfd(1, "██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w      ");
	ft_printfd(1, "  #b█#w██#r█#w        #b█#w██#r█#w      \n     #b█#w");
	ft_printfd(1, "██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  ");
	ft_printfd(1, "#b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r");
	ft_printfd(1, "█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w ");
	ft_printfd(1, "     \n    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w");
	ft_printfd(1, "██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████");
	ft_printfd(1, "████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                 \n");
	if (back)
		back_to_the_future();
}
