/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:38 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:27:38 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_node(t_variable *tmp, int is_env)
{
	if (!is_env)
	{
		free(tmp->name);
		free(tmp->value);
	}
	free(tmp);
}

static void	skip_node(t_variable **node, char *arg, int is_env)
{
	t_variable	*tmp;
	t_variable	*current_node;

	current_node = *node;
	if (!ft_strcmp(arg, current_node->name))
	{
		tmp = current_node;
		(*node) = current_node->next;
		free_node(tmp, is_env);
		return ;
	}
	while (current_node->next)
	{
		if (!ft_strcmp(arg, current_node->next->name))
		{
			tmp = current_node->next;
			current_node->next = current_node->next->next;
			free_node(tmp, is_env);
			return ;
		}
		current_node = current_node->next;
	}
}

/*
	It takes one ore more arguments, UPPERCASE letters only, with OR without $
	If exists : skip next node, replace its address with next next's one
	(in both env and export lists)
*/
void	ft_unset(t_cmdli **cmdli)
{
	int			i;
	char		**args;
	t_shell		*shell;

	g_errno = 0;
	args = (*cmdli)->cmd_args;
	if (!args || !args[0])
		return ;
	i = 1;
	shell = ft_get_shell(NULL);
	while (args[i] && shell->export)
	{
		if (shell->env)
			skip_node(&shell->env, args[i], 1);
		skip_node(&shell->export, args[i], 0);
		++i;
	}
}
