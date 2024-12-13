#include "../../incs/minishell.h"

void	interpret(t_cmdli **cmds_list, char **cmdline,
					t_type *type, unsigned int *i)
{
	while ((*cmdline)[*i] && ((*cmdline)[*i] == ' ' ||
			((*cmdline)[*i] >= '\t' && (*cmdline)[*i] <= '\r')))
		++*i;
	if (!(*cmdline)[*i])
		return ;
	else if ((*cmdline)[*i] == '<')
		type_and_set(split_cmd(cmdline, i, '<'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '>')
		type_and_set(split_cmd(cmdline, i, '>'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '|')
		type_and_set(split_cmd(cmdline, i, '|'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '&')
		type_and_set(split_cmd(cmdline, i, '&'), cmds_list, type, 1);
//	else if ((*cmdline)[*i] == '(')
//		// todo, ajouter fonction pour open parenthese
//		ft_printfd(1, "blablabla '(' %i\n", ++*i);
//	else if ((*cmdline)[*i] == ')')
//		// todo, ajouter fonction pour close parenthese
//		ft_printfd(1, "blablabla ')' %i\n", ++*i);
//	else if ((*cmdline)[*i] == '*' || (*cmdline)[*i] == '$')
//		// todo, ajouter fonction pour expend les matchs
//		ft_printfd(1, "blablabla * and $ %i\n", ++*i);
	else
		type_and_set(split_cmd_sp(cmdline, i), cmds_list, type, 0);
}

t_cmdli	*get_cmds(char **cmdline)
{
	unsigned int	i;
	t_cmdli			*cmds_list;
	t_type			type;

	if (!(*cmdline))
		return (NULL);
	i = 0;
	type = EMPTY;
	cmds_list = NULL;
	while ((*cmdline)[i])
	{
		interpret(&cmds_list, cmdline, &type, &i);
		if (!cmds_list)
			return (NULL);
	}
	if (type != CMD && type != ARG && type != RFILE && type != EMPTY)
		return (error_cmdli_nl(&cmds_list));
	return (cmdli_first(cmds_list));
}
