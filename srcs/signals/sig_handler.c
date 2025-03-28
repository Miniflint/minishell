/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:29:27 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:29:28 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	handle_interrupt(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "\n", 1);
	ft_print_prompt();
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_errno = 1;
}

/*
	mode == 0
		SIG_IGN (in child)
	mode == 1
		custom ctrl + c
	other mode (== 2)
		default ctr + c
*/
void	sig_mode(int mode)
{
	if (!mode)
		signal(SIGINT, SIG_IGN);
	else if (mode == 1)
		signal(SIGINT, &handle_interrupt);
	else
		signal(SIGINT, SIG_DFL);
}

/*
	init term
	no ^C with ECHOCTL option
	applies settings now
*/
void	term_handler(void)
{
	struct termios	term_flag;

	tcgetattr(0, &term_flag);
	term_flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term_flag);
}
