#include "../../incs/minishell.h"

void	file_rdi(t_cmdli **cmds_list, char *file)
{
	char	**tmp;

	tmp = (*cmds_list)->file_in;
	(*cmds_list)->file_in = ft_strsjoin(file, tmp);
	if (tmp)
		free(tmp);
	if (!(*cmds_list)->file_in)
		return (error_cmdli(cmds_list, "minishell: memory allocation failed\n"));
}

void	file_rdo(t_cmdli **cmds_list, char *file, t_type type)
{
	t_file	**tmp;

	tmp = (*cmds_list)->file_out;
	(*cmds_list)->file_out = file_join(file, tmp, type);
	if (tmp)
		free(tmp);
	if (!(*cmds_list)->file_out)
		return (error_cmdli(cmds_list, "minishell: memory allocation failed\n"));
}

void	add_file(t_cmdli **cmds_list, char *file, t_type *type)
{
	if (*type == RDI)
		file_rdi(cmds_list, file);
	else if (*type == RDO)
		file_rdo(cmds_list, file, RDO);
	else if (*type == RDOA)
		file_rdo(cmds_list, file, RDOA);
	else
		write_heredoc(cmds_list, file);
	*type = RFILE;
}
