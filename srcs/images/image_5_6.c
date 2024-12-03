/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_5_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:02:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/02 05:10:19 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
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
