#include "../../incs/minishell.h"

void	open_parenthesis(t_cmdli **cmds_list, t_shell *shell, t_type *type)
{
	*type = OPEN_P;
	++shell->parenthesis;
	++(*cmds_list)->create_fork;
}

void	close_parenthesis(t_cmdli **cmds_list, t_shell *shell, t_type *type)
{
	*type = CLOSE_P;
	--shell->parenthesis;
	++(*cmds_list)->exit_fork;
}

int	check_close_parenthesis(char *s, char *token, t_shell *shell, t_type type)
{
	return (ft_strcmp_int(s, token) && shell->parenthesis - 1 >= 0
		&& shell->parenthesis == shell->cmd_cmpt
		&& (type == CMD || type == ARG || type == RFILE || type == CLOSE_P));
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
	else if (ft_strcmp_int(s, "(") && (*type == EMPTY || *type == PIPE || *type == ANDOR || *type == OPEN_P))
		open_parenthesis(cmds_list, ft_get_shell(NULL), type);
	else if (check_close_parenthesis(s, ")", ft_get_shell(NULL), *type))
		close_parenthesis(cmds_list, ft_get_shell(NULL), type);
	else if (ft_strcmp_int(s, "|")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
		add_pipe(cmds_list, type);
	else if (ft_strcmp_int(s, "||")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
		add_andor(cmds_list, type, 2);
	else if (ft_strcmp_int(s, "&&")
		&& (*type == CMD || *type == ARG || *type == RFILE || *type == CLOSE_P))
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
