/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_1_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:01:39 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/02 05:13:12 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_1(int back)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "#w     ██       ██    ██    ██    ██    ██      ████");
	ft_printfd(1, "██     ██    ██    ████████    ██          ██       ");
	ft_printfd(1, "\n     ███     ███    ██    ███   ██    ██    ███   ");
	ft_printfd(1, " ██    ██    ██    ██     █    ██          ██       ");
	ft_printfd(1, "\n     ████   ████    ██    ████  ██    ██    ███   ");
	ft_printfd(1, "       ██    ██    ██          ██          ██       ");
	ft_printfd(1, "\n     ██ ██ ██ ██    ██    ██ ██ ██    ██      ████");
	ft_printfd(1, "█      ████████    ██████      ██          ██       ");
	ft_printfd(1, "\n     ██  ███  ██    ██    ██  ████    ██          ");
	ft_printfd(1, "███    ██    ██    ██          ██          ██       ");
	ft_printfd(1, "\n     ██   █   ██    ██    ██   ███    ██    ██    ");
	ft_printfd(1, "███    ██    ██    ██     █    ██          ██       ");
	ft_printfd(1, "\n     ██       ██    ██    ██    ██    ██     █████");
	ft_printfd(1, "█      ██    ██    ████████    ████████    ████████ ");
	ft_printfd(1, "#0\n                                                ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "  \n");
	if (back)
		back_to_the_future();
}

void	image_2_a(void)
{
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "                                                  \n");
	ft_printfd(1, "    #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b█#w");
	ft_printfd(1, "██   #b█#w██     #b█#w██████    #b█#w██   #b█#w██   ");
	ft_printfd(1, "#b█#w████████   #b█#w██         #b█#w██       \n    ");
	ft_printfd(1, "#b█#w███    #b█#w███   #b█#w██   #b█#w███  #b█#w██  ");
	ft_printfd(1, " #b█#w██   #b█#w███   #b█#w██   #b█#w██   #b█#w██   ");
	ft_printfd(1, "#b█#w██    #b█#w█   #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w████  #b█#w████   #b█#w██   #b█#w████ #b█#w");
	ft_printfd(1, "██   #b█#w██   #b█#w███         #b█#w██   #b█#w██   ");
	ft_printfd(1, "#b█#w██         #b█#w██         #b█#w██       \n    ");
	ft_printfd(1, "#b█#w██#b█#w██#b█#w██#b█#w██   #b█#w██   #b█#w██#b█");
}

void	image_2(int back)
{
	image_2_a();
	ft_printfd(1, "#w██#b█#w██   #b█#w██     #b█#w█████     #b█#w███████");
	ft_printfd(1, "█   #b█#w██████     #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██ #b█#w███ #b█#w██   #b█#w██   #b█#w██ #b█");
	ft_printfd(1, "#w████   #b█#w██         #b█#w███   #b█#w██   #b█#w█");
	ft_printfd(1, "█   #b█#w██         #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██  #b█#w█  #b█#w██   #b█#w██   #b█#w██  #b");
	ft_printfd(1, "█#w███   #b█#w██   #b█#w██   #b█#w███   #b█#w██   #b");
	ft_printfd(1, "█#w██   #b█#w██    #b█#w█   #b█#w██         #b█#w██ ");
	ft_printfd(1, "      \n    #b█#w██      #b█#w██   #b█#w██   #b█#w██");
	ft_printfd(1, "   #b█#w██   #b█#w██    #b█#w██████     #b█#w██   #b");
	ft_printfd(1, "█#w██   #b█#w████████   #b█#w████████   #b█#w███████");
	ft_printfd(1, "█ \n                                                ");
	ft_printfd(1, "                                                    ");
	ft_printfd(1, "  \n");
	if (back)
		back_to_the_future();
}
