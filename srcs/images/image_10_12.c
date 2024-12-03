/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_10_12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:58:34 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/02 05:10:14 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_10_12_b(int i)
{
	if (i == 1)
	{
		ft_printfd(1, "        #b▀#w▀▀#r▀#w      \n    #b█#w██#r█#w#b█#w███");
		ft_printfd(1, "#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w██");
		ft_printfd(1, "██#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██");
		ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w");
		ft_printfd(1, "        #b█#w██#r█#w      \n   #b█#w██#r█#w #b█#w█#r");
		ft_printfd(1, "█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w██");
		ft_printfd(1, "█#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  ");
		ft_printfd(1, "#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█");
		ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█#w");
		ft_printfd(1, "██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w");
		ft_printfd(1, "  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    ");
		ft_printfd(1, "#b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w");
		ft_printfd(1, "████████#r█#w  #b█#w████████#r█#w\n                 ");
		ft_printfd(1, "                                                    ");
		ft_printfd(1, "                                 \n");
		return ;
	}
	ft_printfd(1, "       \n    #b█#w██      #b█#w██   #b█#w██   #b█#w█");
	ft_printfd(1, "█   #b█#w██   #b█#w██    #b█#w██████     #b█#w██   ");
	ft_printfd(1, "#b█#w██   #b█#w████████   #b█#w████████   #b█#w██████");
	ft_printfd(1, "██ \n                                               ");
	ft_printfd(1, "                                                    ");
}

void	image_10(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████");
	ft_printfd(1, "#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w██#r█#w      \n      #b");
	ft_printfd(1, "█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███");
	ft_printfd(1, "#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█");
	ft_printfd(1, "#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  ");
	ft_printfd(1, " #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      ");
	ft_printfd(1, "\n    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  ");
	ft_printfd(1, "#b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█");
	ft_printfd(1, "#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  ");
	ft_printfd(1, "      #b█#w██#r█#w        #b█#w██#r█#w      \n  #b▀");
	ft_printfd(1, "#w▀▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w  #b▀#w▀▀#p▀");
	ft_printfd(1, "#w▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    #b▀#w▀▀▀▀▀#r▀#w    ");
	ft_printfd(1, "#b▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r▀#w    #b▀#w▀▀#r▀#w");
	image_10_12_b(1);
	if (back)
		back_to_the_future();
}

void	image_11_b(void)
{
	ft_printfd(1, "      #b▄#w▄▄#r▄#w      \n     #b█#w██#r█#w#b█#w███");
	ft_printfd(1, "#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w███");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r");
	ft_printfd(1, "█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w ");
	ft_printfd(1, "       #b█#w██#r█#w      \n    #b█#w██#r█#w #b█#w█#r");
	ft_printfd(1, "█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w██");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  ");
	ft_printfd(1, "#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w██#r█#w      \n         ");
	ft_printfd(1, "    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r");
	ft_printfd(1, "█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████");
	ft_printfd(1, "#r█#w  #b█#w████████#r█#w\n#b█#w██#r█#w             ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                 \n");
}

void	image_11(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                #b█#w██#r█#w        ");
	ft_printfd(1, "      \n    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r");
	ft_printfd(1, "█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█");
	ft_printfd(1, "#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███");
	ft_printfd(1, "█████#r█#w              #b█#w██#r█#w      \n    #b█");
	ft_printfd(1, "#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█");
	ft_printfd(1, "#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   ");
	ft_printfd(1, "#b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█");
	ft_printfd(1, "#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w");
	ft_printfd(1, "        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    ");
	ft_printfd(1, "    #b█#w██#r█#w        #b█#w██#r█#w      \n  #b▄#w▄");
	ft_printfd(1, "▄#p▄#w▄▄▄▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w  #b▄#w▄▄#p▄#w▄");
	ft_printfd(1, "▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w    #b▄#w▄▄▄▄▄#r▄#w    #b");
	ft_printfd(1, "▄#w▄▄▄▄▄▄▄▄#r▄#w  #b▄#w▄▄▄▄▄▄#r▄#w    #b▄#w▄▄#r▄#w  ");
	image_11_b();
	if (back)
		back_to_the_future();
}

void	image_12(int back)
{
	ft_printfd(1, "       #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b");
	ft_printfd(1, "█#w██   #b█#w██     #b█#w██████    #b█#w██   #b█#w██");
	ft_printfd(1, "   #b█#w████████   #b█#w██         #b█#w██     \n   ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                               \n   ");
	ft_printfd(1, " #b█#w███    #b█#w███   #b█#w██   #b█#w███  #b█#w██ ");
	ft_printfd(1, "  #b█#w██   #b█#w███   #b█#w██   #b█#w██   #b█#w██  ");
	ft_printfd(1, " #b█#w██    #b█#w█   #b█#w██         #b█#w██       ");
	ft_printfd(1, "\n    #b█#w████  #b█#w████   #b█#w██   #b█#w████ #b█");
	ft_printfd(1, "#w██   #b█#w██   #b█#w███         #b█#w██   #b█#w██  ");
	ft_printfd(1, " #b█#w██         #b█#w██         #b█#w██       \n   ");
	ft_printfd(1, " #b█#w██#b█#w██#b█#w██#b█#w██   #b█#w██   #b█#w██#b█");
	ft_printfd(1, "#w██#b█#w██   #b█#w██     #b█#w█████     #b█#w██████");
	ft_printfd(1, "██   #b█#w██████     #b█#w██         #b█#w██       ");
	ft_printfd(1, "\n    #b█#w██ #b█#w███ #b█#w██   #b█#w██   #b█#w██ #b");
	ft_printfd(1, "█#w████   #b█#w██         #b█#w███   #b█#w██   #b█#w");
	ft_printfd(1, "██   #b█#w██         #b█#w██         #b█#w██       ");
	ft_printfd(1, "\n    #b█#w██  #b█#w█  #b█#w██   #b█#w██   #b█#w██  ");
	ft_printfd(1, "#b█#w███   #b█#w██   #b█#w██   #b█#w███   #b█#w██   ");
	ft_printfd(1, "#b█#w██   #b█#w██    #b█#w█   #b█#w██         #b█#w██");
	ft_printfd(1, "   \n");
	image_10_12_b(0);
	if (back)
		back_to_the_future();
}
