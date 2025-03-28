/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:36 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:16 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	interpret_func(char *s, t_cmdli **cmds_list, t_type *type, int rd)
{
	if (ft_strcmp_int(s, "<") && !rd)
		*type = RDI;
	else if (ft_strcmp_int(s, "<<") && !rd)
		*type = RDIH;
	else if (ft_strcmp_int(s, ">") && !rd)
		*type = RDO;
	else if (ft_strcmp_int(s, ">>") && !rd)
		*type = RDOA;
	else if (ft_strcmp_int(s, "(") && (*type == EMPTY || *type == PIPE
			|| *type == ANDOR || *type == OPEN_P))
		open_parenthesis(cmds_list, ft_get_shell(NULL), type);
	else if (check_close_parenthesis(s, ")", ft_get_shell(NULL), *type))
		close_parenthesis(cmds_list, ft_get_shell(NULL), type);
	else if (ft_strcmp_int(s, "|")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
		add_pipe(cmds_list, type);
	else if (ft_strcmp_int(s, "||")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
		add_andor(cmds_list, type, OR_VALUE);
	else if (ft_strcmp_int(s, "&&")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
		add_andor(cmds_list, type, AND_VALUE);
	else
		return (error_cmdli_interpret(cmds_list, s));
	free(s);
}

void	set_type(t_shell *shell, t_type *type, int rd)
{
	if (*type == CMD || *type == ARG)
		*type = ARG;
	else if (!rd)
	{
		shell->cmd_cmpt = shell->parenthesis;
		*type = CMD;
	}
}

void	type_and_set(char *s, t_cmdli **cmds_list, t_type *type, int interpret)
{
	int	rd;

	if (!s)
		return (error_cmdli(cmds_list, "memory allocation failed\n"));
	rd = 0;
	if (*type == RDI || *type == RDO || *type == RDIH || *type == RDOA)
		rd = 1;
	if (!*cmds_list)
		*cmds_list = create_cmdli();
	if (!*cmds_list)
		return ;
	if (interpret)
		interpret_func(s, cmds_list, type, rd);
	else
	{
		if (*type == CLOSE_P)
			return (error_cmdli_interpret_s(cmds_list, s));
		set_type(ft_get_shell(NULL), type, rd);
		if (*type == RDIH)
			write_heredoc(cmds_list, s);
		else if (new_unlist(*cmds_list, s, *type))
			return (error_cmdli(cmds_list, "memory allocation failed\n"));
		if (rd)
			*type = RFILE;
	}
}
