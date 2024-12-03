/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:46:34 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 16:19:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
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
