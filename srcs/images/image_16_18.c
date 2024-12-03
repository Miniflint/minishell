/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_16_18.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:58:12 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/02 05:10:12 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_16_17_b(int i)
{
	if (i == 1)
	{
		ft_printfd(1, "░#r░#w #b▒#w█#r█#w #b█#w██#r█#w  #b█#w█▒#r█#w  #b░#w");
		ft_printfd(1, "▒#r█#w #b█#w▒██#r█#w  #b█#w██#r█#w  #b█#w▒#r█#w  #b█");
		ft_printfd(1, "#w░░█#r█#w  #b█#w░░#r█#w  #b█#w██#r█#w  #b█#w██#r█#w");
		ft_printfd(1, "   #b█#w█#r█#w  #b█#w▒█#r█#w        #b░#w░▒#r▒#w    ");
		ft_printfd(1, "  \n   #b░#w░░#r░#w     #b█#w█░#r░#w  #b█#w▒#r█#w  ");
		ft_printfd(1, "#b█#w██#r░#w  #b█#w▒#r█#w  #b█#w██#r█#w   #b█#w█░░▒█▒");
		ft_printfd(1, "#r▒#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w▒███▒#r▒#w");
		ft_printfd(1, "  #b▒#w▒█████▒#r▒#w  #b█#w░▒██░░#r█#w\n             ");
		ft_printfd(1, "                                                    ");
		ft_printfd(1, "                                     \n  #b▄#w▄▄#p▄");
		ft_printfd(1, "#w▄▄▄▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w  #b▄#w▄▄#p▄#w▄▄#p▄");
		ft_printfd(1, "#w▄▄#r▄#w  #b▄#w▄▄#r▄#w    #b▄#w▄▄▄▄▄#r▄#w    #b▄#w▄▄");
		ft_printfd(1, "▄▄▄▄▄▄#r▄#w  #b▄#w▄▄▄▄▄▄#r▄#w    #b▄#w▄▄#r▄#w       ");
		ft_printfd(1, " #b▄#w▄▄#r▄#w      \n");
	}
	else
	{
		ft_printfd(1, "    #b▒#w░░      #b█#w██   #b█#w██   #b█#w██   #b█#w");
		ft_printfd(1, "▒█   #b▒#w▒█    #b█#w░░██░░     #b▒#w▒   #b░#w░░   ");
		ft_printfd(1, "#b█#w░░▒███▒   #b█#w░░███▒█   #b█#w▒████░░ \n        ");
		ft_printfd(1, "                                                    ");
		ft_printfd(1, "                                          \n");
	}
}

void	image_16(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "      #b░#w▒░#r█#w     #b█#w░▒#r█#w  #b█#w▒█#r█#w  ");
	ft_printfd(1, "#b█#w░░#r░#w  #b█#w██#r█#w  #b█#w█▒#r▒#w    #b░#w░░▒█");
	ft_printfd(1, "█#r█#w   #b█#w█▒#r▒#w  #b█#w▒#r▒#w  #b█#w░░███░░█#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w        #b█#w█▒#r░#w      \n    #b█");
	ft_printfd(1, "#w█▒#r▒#w   #b█#w█░░#r█#w  #b░#w░▒#r█#w  #b█#w▒██#r█");
	ft_printfd(1, "#w #b░#w░░#r░#w  #b█#w█▒#r▒#w  #b█#w███#r█#w  #b█#w░█");
	ft_printfd(1, "#r░#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b");
	ft_printfd(1, "█#w▒#r░#w  #b█#w▒#r▒#w        #b▒#w█░#r░#w      \n  ");
	ft_printfd(1, "  #b░#w░░██#r█#w #b█#w▒██#r█#w  #b█#w██#r█#w  #b█#w█");
	ft_printfd(1, "░░█#r█#w#b█#w██#r█#w  #b▒#w██#r▒#w  #b░#w░░░#r░#w   ");
	ft_printfd(1, "     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w       ");
	ft_printfd(1, " #b░#w░█#r█#w        #b█#w██#r█#w      \n     #b░#w░");
	ft_printfd(1, "░#r░#w#b█#w██░#r█#w#b█#w██#r█#w  #b█#w░░#r█#w  #b█#w");
	ft_printfd(1, "█░#r█#w#b█#w░░██#r█#w  #b█#w█░#r█#w        #b█#w█▒░");
	ft_printfd(1, "#r█#w  #b█#w░█#r█#w  #b█#w██#r█#w  #b█#w█▒#r▒#w      ");
	ft_printfd(1, "  #b█#w██#r█#w        #b█#w▒#r▒#w      \n     #b░#w░");
	image_16_17_b(1);
	if (back)
		back_to_the_future();
}

void	image_17(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "    #b█#w░░      #b░#w██   #b░#w██   #b█#w██   #b▒#w");
	ft_printfd(1, "█▒   #b█#w██     #b█#w░░███▒    #b█#w█▒   #b░#w░█   ");
	ft_printfd(1, "#b█#w█░░██▒░░   #b░#w░░         #b░#w██       \n    ");
	ft_printfd(1, "#b█#w██░    #b░#w▒█▒   #b░#w██   #b█#w░░█  #b█#w▒█  ");
	ft_printfd(1, " #b█#w██   #b█#w░░█   #b░#w██   #b█#w██   #b█#w██   ");
	ft_printfd(1, "#b█#w█▒    #b█#w█   #b█#w▒         #b█#w█░       \n ");
	ft_printfd(1, "     #b█#w███░  #b█#w░▒█   #b░#w██   #b█#w▒███ #b█#w");
	ft_printfd(1, "▒█   #b█#w██   #b█#w█░░         #b░#w██   #b█#w██   ");
	ft_printfd(1, "#b█#w██         #b█#w██         #b█#w░█       \n    ");
	ft_printfd(1, "#b▒#w▒█#b█#w██#b█#w██#b█#w▒   #b█#w██   #b█#w██#b█#w");
	ft_printfd(1, "██#b█#w██   #b█#w██     #b█#w▒██     #b▒#w▒█████░░  ");
	ft_printfd(1, " #b█#w░░▒███     #b█#w█▒         #b█#w█░       \n  ");
	ft_printfd(1, "#b▒#w██ #b█#w███ #b█#w██   #b█#w░░   #b█#w██ #b█#w░██");
	ft_printfd(1, "█   #b░#w░█         #b█#w███   #b█#w██   #b▒#w▒█   ");
	ft_printfd(1, "#b░#w░█         #b█#w██         #b█#w██       \n    ");
	ft_printfd(1, "#b▒#w░░  #b█#w█  #b█#w██   #b█#w██   #b█#w██  #b█#w▒ ");
	ft_printfd(1, "  #b░#w░█   #b█#w██   #b▒#w▒██   #b█#w██   #b░#w██  ");
	ft_printfd(1, " #b█#w██    #b█#w█   #b█#w░░         #b▒#w▒       \n");
	image_16_17_b(0);
	if (back)
		back_to_the_future();
}

void	image_18_b(void)
{
	ft_printfd(1, "█#r█#w   ░░#r█#w         ██░#r█#w   ██#r█#w   ██#r█");
	ft_printfd(1, "#w   ██#r█#w         ██#r█#w         █░#r░#w      \n ");
	ft_printfd(1, "     ░░#r░#w  █#r█#w  ██#r█#w   ██#r░#w   ██#r█#w  █");
	ft_printfd(1, "██#r▒#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   █");
	ft_printfd(1, "█#r█#w   ██#r█#w    ░#r░#w   ░█#r█#w         ░░#r█#w");
	ft_printfd(1, "      \n     ██#r█#w      ██#r█#w   ▒█#r▒#w   ██#r▒");
	ft_printfd(1, "#w   ██#r▒#w   ▒#r▒#w    ░░██░░#r█#w     ░█#r░#w   ██");
	ft_printfd(1, "#r░#w   ░░██▒░░#r░#w   ░░▒████▒#r░#w   ░░▒███░#r░#w");
	ft_printfd(1, "\n                                                   ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "  \n ");
}

void	image_18(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "        ▒░░#r█#w    ▒█#r▒#w   █▒#r█#w   █░░#r█#w  ██");
	ft_printfd(1, "#r█#w   ██#r█#w   ██░#r█#w   █░#r█#w   ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ▒░#r░#w    ░#r█#w   ██#r█#w         ▒#r░#w   ");
	ft_printfd(1, "   \n        #w░░#r▒#w      █░#r░#w   ██#r█#w   ██#r");
	ft_printfd(1, "█#w   ██#r█#w   ██#r█#w     ░░░██░#r█#w    ██#r█#w  ");
	ft_printfd(1, " ░░#r█#w   ░▒███░░#r█#w   ██#r█#w         ░░#r█#w   ");
	ft_printfd(1, "   \n      █░#r░#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ");
	ft_printfd(1, "██#r█#w██#r█#w██#r█#w   ██#r█#w     ▒░▒░#r█#w     ░░");
	ft_printfd(1, "▒████#r▒#w   ░░████      ░░#r█#w         █░#r░#w    ");
	ft_printfd(1, "  \n     ▒░░#r█#w  ▒█░░#r▒#w   █▒#r█#w   █░░░#r█#w █");
	ft_printfd(1, "█#r█#w   ░░#r█#w   ░██#r█#w         ▒█#r█#w   ░░#r█");
	ft_printfd(1, "#w   ██#r█#w         ██#r█#w         ██#r█#w      \n ");
	ft_printfd(1, "    ██#r█#w ░██#r█#w ██#r█#w   ██#r░#w   █░#r█#w █░█");
	image_18_b();
	if (back)
		back_to_the_future();
}
