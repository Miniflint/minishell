/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_19_20.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:29 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:27:31 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_19_b(void)
{
	ft_printfd(1, "#b█#w░░██#r█#w  #b█#w██#r░#w  #b█#w░░██#r█#w#b█#w█░");
	ft_printfd(1, "#r░#w  #b█#w██#r░#w  #b█#w███#r█#w        #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w   ");
	ft_printfd(1, "     #b█#w██#r█#w      \n   #b░#w░░#r█#w#b█#w███#r█");
	ft_printfd(1, "#w#b█#w██#r█#w  #b█#w█░#r█#w  #b█#w██#r█#w#b█#w░░██#r");
	ft_printfd(1, "█#w  #b█#w██#r█#w        #b█#w░░░#r░#w  #b█#w██#r█#w");
	ft_printfd(1, "  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w    ");
	ft_printfd(1, "    #b█#w░░#r█#w      \n    #b░#w██#r█#w     #b█#w██");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b░");
	ft_printfd(1, "#w█░#r█#w   #b█#w░░██░░#r█#w    #b█#w░░#r█#w  #b░#w░");
	ft_printfd(1, "█#r█#w  #b█#w█░░███░░#r█#w  #b█#w░░██████#r█#w  #b█");
	ft_printfd(1, "#w░░████░░#r█#w\n                                    ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "              \n    #b░#w██#r█#w #b█#w█#r░#w #b█#w██");
	ft_printfd(1, "#r█#w  #b█#w██#r█#w  #b█#w█░#r░#w #b█#w███#r█#w  #b█");
	ft_printfd(1, "#w██#r█#w  #b█#w██#r█#w  #b░#w░░█#r█#w  #b░#w░█#r█#w");
	ft_printfd(1, "  #b█#w░░#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w        #b█#w░░#r█#w      \n");
}

void	image_19(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "  #b░#w█░#r░#w     #b█#w██#r░#w  #b█#w██#r░#w  #b█#w");
	ft_printfd(1, "█░#r█#w  #b█#w█░#r░#w  #b░#w█░#r█#w    #b░#w░████░#r");
	ft_printfd(1, "█#w   #b█#w██#r█#w  #b█#w░░#r█#w  #b█#w░░████░░#r█#w");
	ft_printfd(1, "  #b░#w░█#r░#w        #b░#w░█#r░#w      \n    #b░#w░");
	ft_printfd(1, "░#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w██#p");
	ft_printfd(1, "█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w░░███#r█#w  ");
	ft_printfd(1, "  #b█#w░░░█████#r█#w  #b█#w░████░     #b█#w██#r█#w  ");
	ft_printfd(1, "      #b█#w██#r█#w      \n    #b░#w██░#r░#w   #b█#w░");
	ft_printfd(1, "░█#r░#w  #b█#w█░#r█#w  #b█#w██░#r█#w #b█#w█░#r░#w  ");
	ft_printfd(1, "#b░#w██#r░#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w░░#r█#w   #b░#w░#r░#w  #b█#w█");
	ft_printfd(1, "█#r█#w        #b█#w██#r░#w      \n   #b░#w████#r░#w ");
	image_19_b();
	if (back)
		back_to_the_future();
}

void	image_20_b(void)
{
	ft_printfd(1, "\n      #b░#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w");
	ft_printfd(1, "░░#r█#w  #b█#w██#r█#w #b░#w█░█#r░#w  #b█#w██#r█#w  ");
	ft_printfd(1, "#b█#w██#r█#w  #b█#w███#r█#w  #b█#w█░#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w   #b░#w░#r░#w  #b█#w██#r█#w        ");
	ft_printfd(1, "#b█#w██#r█#w      \n     #b█#w██#r█#w#b█#w░░█#r█#w#b");
	ft_printfd(1, "░#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w");
	ft_printfd(1, "  #b█#w░░#r░#w        #b█#w░██#r░#w  #b█#w██#r█#w  ");
	ft_printfd(1, "#b█#w██#r█#w  #b█#w░░#r░#w        #b█#w██#r█#w       ");
	ft_printfd(1, " #b█#w██#r█#w      \n    #b█#w██#r█#w     #b█#w██#r█");
	ft_printfd(1, "#w  #b█#w██#r█#w  #b█#w█░#r░#w  #b█#w██#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w   #b░#w░█████#r█#w    #b█#w██#r█#w  #b█#w██#r");
	ft_printfd(1, "█#w  #b█#w████████#r█#w  #b█#w████░░░░#r█#w  #b█#w██");
	ft_printfd(1, "██████#r█#w\n  #b▀#w▀▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀");
	ft_printfd(1, "▀#r▀#w  #b▀#w▀▀#p▀#w▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    ");
	ft_printfd(1, "#b▀#w▀▀▀▀▀#r▀#w    #b▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r");
	ft_printfd(1, "▀#w    #b▀#w▀▀#r▀#w        #b▀#w▀▀#r▀#w      \n     ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                             \n");
}

void	image_20(int back)
{
	ft_printfd(1, "        #b░#w██#r█#w     #b█#w██#r░#w  #b█#w░░#r░#w ");
	ft_printfd(1, " #b█#w██#r█#w  #b█#w░█#r█#w  #b█#w█░#r█#w    #b░#w░░");
	ft_printfd(1, "████#r█#w   #b█#w░█#r█#w  #b█#w░█#r█#w  #b█#w█████░░");
	ft_printfd(1, "░#r░#w  #b█#w██#r█#w        #b░#w░█#r░#w      \n    ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                              \n    ");
	ft_printfd(1, "    #b█#w█░█#r█#w   #b█#w░██#r█#w  #b█#w░░#r░#w  #b█");
	ft_printfd(1, "#w░██#r█#w #b█#w██#r█#w  #b░#w██#r█#w  #b█#w█░░#r█#w");
	ft_printfd(1, "  #b░#w██#r█#w  #b█#w█░#r█#w  #b█#w█░#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w   #b█#w█#r░#w  #b█#w██#r█#w        #b█#w░░#r█#w");
	ft_printfd(1, "      \n      #b█#w░███#r█#w #b█#w██░█#r█#w  #b█#w██");
	ft_printfd(1, "#r█#w  #b█#w░███#r█#w#b█#w██#r█#w  #b█#w█░#r█#w  #b█");
	ft_printfd(1, "#w███#r█#w        #b░#w░█#r░#w  #b█#w░░#r█#w  #b█#w█");
	ft_printfd(1, "█#r█#w        #b█#w██#r░#w        #b█#w██#r█#w      ");
	image_20_b();
	if (back)
		back_to_the_future();
}
