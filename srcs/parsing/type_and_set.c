#include "../../incs/minishell.h"

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
		if (*type == CMD || *type == ARG)
			*type = ARG;
		else if (!rd)
			*type = CMD;
		if (*type == RDIH)
			write_heredoc(cmds_list, s);
		else if (new_unlist(*cmds_list, s, *type))
			return (error_cmdli(cmds_list, "memory allocation failed\n"));
		if (rd)
			*type = RFILE;
	}
}
