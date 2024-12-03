/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:34:44 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/12/02 05:14:18 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	ft_sleep(unsigned int time)
{
	unsigned int	i;

	while (time--)
	{
		i = 0;
		while (i < 350000)
			i++;
	}
}

void	back_to_the_future(void)
{
	unsigned int	i;

	i = 0;
	write(1, "\r", 1);
	while (i < 9)
	{
		i++;
		ft_printfd(1, "\033[A");
	}
}

// void	print_minishell(void)
// {
// 	ft_printfd(1, "IMAGE 1 :\n");
// 	image_1(0);
// 	ft_printfd(1, "IMAGE 2 :\n");
// 	image_2(0);
// 	ft_printfd(1, "IMAGE 3 :\n");
// 	image_3(0);
// 	ft_printfd(1, "IMAGE 4 :\n");
// 	image_4(0);
// 	ft_printfd(1, "IMAGE 5 :\n");
// 	image_5(0);
// 	ft_printfd(1, "IMAGE 6 :\n");
// 	image_6(0);
// 	ft_printfd(1, "IMAGE 7 :\n");
// 	image_7(0);
// 	ft_printfd(1, "IMAGE 8 :\n");
// 	image_8(0);
// 	ft_printfd(1, "IMAGE 9 :\n");
// 	image_9(0);
// 	ft_printfd(1, "IMAGE 10 :\n");
// 	image_10(0);
// 	ft_printfd(1, "IMAGE 11 :\n");
// 	image_11(0);
// 	ft_printfd(1, "IMAGE 12 :\n");
// 	image_12(0);
// 	ft_printfd(1, "IMAGE 13 :\n");
// 	image_13(0);
// 	ft_printfd(1, "IMAGE 14 :\n");
// 	image_14(0);
// 	ft_printfd(1, "IMAGE 15 :\n");
// 	image_15(0);
// 	ft_printfd(1, "IMAGE 16 :\n");
// 	image_16(0);
// 	ft_printfd(1, "IMAGE 17 :\n");
// 	image_17(0);
// 	ft_printfd(1, "IMAGE 18 :\n");
// 	image_18(0);
// 	ft_printfd(1, "IMAGE 19 :\n");
// 	image_19(0);
// 	ft_printfd(1, "IMAGE 20 :\n");
// 	image_20(0);
// }

void	first_images(void)
{
	image_1(1);
	ft_sleep(600);
	image_2(1);
	ft_sleep(200);
	image_8(1);
	ft_sleep(80);
	image_1(1);
	ft_sleep(400);
	image_13(1);
	ft_sleep(200);
	image_11(1);
	ft_sleep(80);
	image_10(1);
	ft_sleep(100);
	image_20(1);
	ft_sleep(50);
	image_17(1);
	ft_sleep(100);
	image_12(1);
	ft_sleep(200);
	image_4(1);
	ft_sleep(500);
	image_8(1);
	ft_sleep(150);
}

void	print_minishell(void)
{
	ft_printfd(1, "\n\n");
	ft_say("Welcome to the best minishell");
	first_images();
	image_10(1);
	ft_sleep(200);
	image_7(1);
	ft_sleep(100);
	image_18(1);
	ft_sleep(80);
	image_20(1);
	ft_sleep(200);
	image_6(0);
	ft_printfd(1, "\n\n");
	wait(NULL);
}
