/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_7_9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:00:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/02 05:10:19 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_7_8_b(int i)
{
	if (i == 1)
	{
		ft_printfd(1, "█#w███   #b█#w██   #b█#w██   #b█#w███   #b█#w██   #b");
		ft_printfd(1, "█#w██   #b█#w██    #b█#w█   #b█#w██         #b█#w██ ");
		ft_printfd(1, "      \n    #b█#w██      #b█#w██   #b█#w██   #b█#w██");
		ft_printfd(1, "   #b█#w██   #b█#w██    #b█#w██████     #b█#w██   #b");
		ft_printfd(1, "█#w██   #b█#w████████   #b█#w████████   #b█#w███████");
		ft_printfd(1, "█ \n                                                ");
		ft_printfd(1, "                                                    ");
		ft_printfd(1, "  \n");
		return ;
	}
	ft_printfd(1, "#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "    ██#r█#w  █#r█#w  ██#r█#w   ██#r█#w   ██#r█#w  ██");
	ft_printfd(1, "█#r█#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w ");
	ft_printfd(1, "     \n     ██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ██#r█#w   ██#r█#w    ██████#r█#w     ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ████████#r█#w   ████████#r█#w   ████████#r█");
	ft_printfd(1, "#w\n                                                 ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, " \n");
}

void	image_7(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "       #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b");
	ft_printfd(1, "█#w██   #b█#w██     #b█#w██████    #b█#w██   #b█#w██");
	ft_printfd(1, "   #b█#w████████   #b█#w██         #b█#w██       \n ");
	ft_printfd(1, "     #b█#w███    #b█#w███   #b█#w██   #b█#w███  #b█");
	ft_printfd(1, "#w██   #b█#w██   #b█#w███   #b█#w██   #b█#w██   #b█#w");
	ft_printfd(1, "██   #b█#w██    #b█#w█   #b█#w██         #b█#w██    ");
	ft_printfd(1, " \n    #b█#w████  #b█#w████   #b█#w██   #b█#w████ #b");
	ft_printfd(1, "█#w██   #b█#w██   #b█#w███         #b█#w██   #b█#w██");
	ft_printfd(1, "   #b█#w██         #b█#w██         #b█#w██       \n ");
	ft_printfd(1, " #b█#w██#b█#w██#b█#w██#b█#w██   #b█#w██   #b█#w██#b█");
	ft_printfd(1, "#w██#b█#w██   #b█#w██     #b█#w█████     #b█#w██████");
	ft_printfd(1, "██   #b█#w██████     #b█#w██         #b█#w██       ");
	ft_printfd(1, "\n    #b█#w██ #b█#w███ #b█#w██   #b█#w██   #b█#w██ #b");
	ft_printfd(1, "█#w████   #b█#w██         #b█#w███   #b█#w██   #b█#w");
	ft_printfd(1, "██   #b█#w██         #b█#w██         #b█#w██       ");
	ft_printfd(1, "\n   #b█#w██  #b█#w█  #b█#w██   #b█#w██   #b█#w██  #b");
	image_7_8_b(1);
	if (back)
		back_to_the_future();
}

void	image_8(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "     #w██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██");
	ft_printfd(1, "#r█#w   ██#r█#w     ██████#r█#w    ██#r█#w   ██#r█#w");
	ft_printfd(1, "   ████████#r█#w   ██#r█#w         ██#r█#w      \n  ");
	ft_printfd(1, "     ███#r█#w    ███#r█#w   ██#r█#w   ███#r█#w  ██#r");
	ft_printfd(1, "█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█");
	ft_printfd(1, "#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w    ");
	ft_printfd(1, "  \n     ████#r█#w  ████#r█#w   ██#r█#w   ████#r█#w ");
	ft_printfd(1, "██#r█#w   ██#r█#w   ███#r█#w         ██#r█#w   ██#r█");
	ft_printfd(1, "#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ██#r█");
	ft_printfd(1, "#w██#r█#w██#r█#w   ██#r█#w     █████#r█#w     ███████");
	ft_printfd(1, "█#r█#w   ██████      ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w ███#r█#w ██#r█#w   ██#r█#w   ██#r█#w ██");
	ft_printfd(1, "██#r█#w   ██#r█#w         ███#r█#w   ██#r█#w   ██#r█");
	image_7_8_b(0);
	if (back)
		back_to_the_future();
}

void	image_9_b(void)
{
	ft_printfd(1, "#w    #b█#w████████#r█#w  #b█#w██████     #b█#w██#r█");
	ft_printfd(1, "#w        #b█#w██#r█#w      \n    #b█#w██#r█#w#b█#w█");
	ft_printfd(1, "██#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w");
	ft_printfd(1, "████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█");
	ft_printfd(1, "#w        #b█#w██#r█#w      \n   #b█#w██#r█#w #b█#w█");
	ft_printfd(1, "#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w");
	ft_printfd(1, "███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r");
	ft_printfd(1, "█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n    #b█");
	ft_printfd(1, "#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w   ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█");
	ft_printfd(1, "#w████████#r█#w  #b█#w████████#r█#w\n               ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                   \n");
}

void	image_9(int back)
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
	ft_printfd(1, "      #b█#w██#r█#w        #b█#w██#r█#w      \n    #b");
	ft_printfd(1, "█#w██#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w");
	ft_printfd(1, "██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w█████#r█");
	image_9_b();
	if (back)
		back_to_the_future();
}
