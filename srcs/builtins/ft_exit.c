/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:57 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/02 03:38:03 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	check_exit_code(char **args)
{
	unsigned int	i;

	if (!args || !args[1])
		return (g_errno);
	i = 0;
	if ((args[1][0] == '-' || args[1][0] == '+') && args[1][1])
		i++;
	while (args[1][i] && (args[1][i] >= '0' && args[1][i] <= '9'))
		i++;
	if (args[1][i])
	{
		ft_printfd(2,
			"#+wminishell#0: exit: %s: #/rnumeric argument required#0\n",
			args[1]);
		return (255);
	}
	return (ft_atoi(args[1]));
}

static void	free_shell_variables(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	if (shell->export)
		free_nodes_contents(&shell->export);
	if (shell->env)
		free_nodes(&shell->env);
}

void	ft_exit(t_cmdli **cmdli)
{
	int	code;

	code = check_exit_code((*cmdli)->cmd_args);
	if (code != 255 && (*cmdli)->cmd_args && (*cmdli)->cmd_args[1]
		&& (*cmdli)->cmd_args[2])
	{
		ft_printfd(2, "#+wminishell#0: exit: #/rtoo many arguments#0\n");
		g_errno = 1;
		return ;
	}
	print_and_say("Good bye ! See you soon ;)", "Good bye ! See you soon !");
	free_shell_variables();
	free_cmdli(cmdli);
	if (ft_get_shell(NULL)->read)
		free(ft_get_shell(NULL)->read);
	clear_history();
	exit(code % 256);
}

void	ft_sig_exit(void)
{
	print_and_say("Good bye ! See you soon ;)", "Good bye ! See you soon !");
	free_shell_variables();
	if (ft_get_shell(NULL)->read)
		free(ft_get_shell(NULL)->read);
	clear_history();
	exit(g_errno);
}
