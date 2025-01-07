/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:53:52 by hermesrolle       #+#    #+#             */
/*   Updated: 2025/01/07 16:12:15 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	open_parenthesis(t_cmdli **cmds_list, t_shell *shell)
{
	++shell->parenthesis;
	++(*cmds_list)->create_fork;
}

void	close_parenthesis(t_cmdli **cmds_list, t_shell *shell)
{
	--shell->parenthesis;
	++(*cmds_list)->exit_fork;
}

int	check_close_parenthesis(char *s, char *token, t_shell *shell, t_type type)
{
	if (ft_strcmp_int(s, token) && shell->parenthesis - 1 >= 0
		&& shell->parenthesis == shell->cmd_cmpt
		&& (type == CMD || type == ARG || type == RFILE))
		return (1);
	return (0);
}

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
	else if (ft_strcmp_int(s, "("))
		open_parenthesis(cmds_list, ft_get_shell(NULL));
	else if (check_close_parenthesis(s, ")", ft_get_shell(NULL), *type))
		close_parenthesis(cmds_list, ft_get_shell(NULL));
	else if (ft_strcmp_int(s, "|")
		&& (*type == CMD || *type == ARG || *type == RFILE))
		add_pipe(cmds_list, type);
	else if (ft_strcmp_int(s, "||")
		&& (*type == CMD || *type == ARG || *type == RFILE))
		add_andor(cmds_list, type, 2);
	else if (ft_strcmp_int(s, "&&")
		&& (*type == CMD || *type == ARG || *type == RFILE))
		add_andor(cmds_list, type, 1);
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
{ //Ici récupérer les éléments dans tokens au lieux de set direct le cmdli
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
		set_type(ft_get_shell(NULL), type, rd);
		if (*type == RDIH)
			write_heredoc(cmds_list, s);
		else if (new_unlist(*cmds_list, s, *type))
			return (error_cmdli(cmds_list, "memory allocation failed\n"));
		if (rd)
			*type = RFILE;
	}
}
