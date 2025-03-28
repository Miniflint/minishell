/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmdli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:23 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:19 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

t_cmdli	*error_cmdli_nl(t_cmdli **cmds_list)
{
	free_cmdli(cmds_list);
	ft_printfd(2, "#+wminishell#0: #/r"
		"syntax error near unexpected token `#0newline#/r'#0\n");
	g_errno = 258;
	return (NULL);
}

void	error_cmdli(t_cmdli **cmds_list, char *s)
{
	free_cmdli(cmds_list);
	g_errno = 1;
	ft_printfd(2, "#+wminishell#0: #/r%s#0\n", s);
}

void	error_cmdli_interpret(t_cmdli **cmds_list, char *s)
{
	free_cmdli(cmds_list);
	ft_printfd(2, "#+wminishell#0: #/r"
		"syntax error near unexpected token `#0%.2s#/r'#0\n", s);
	g_errno = 258;
	free(s);
}

void	error_cmdli_interpret_s(t_cmdli **cmds_list, char *s)
{
	free_cmdli(cmds_list);
	ft_printfd(2, "#+wminishell#0: #/r"
		"syntax error near unexpected token `#0%s#/r'#0\n", s);
	g_errno = 258;
	free(s);
}
