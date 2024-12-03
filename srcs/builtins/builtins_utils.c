/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:52:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 14:49:17 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	add_and_free_new_value(t_variable *current, t_variable *new)
{
	current->value = new->value;
	free(new->name);
	free(new);
}

static void	add_new_node_to_null(t_variable **env, t_variable *new)
{
	*env = malloc(sizeof(t_variable));
	(*env)->name = new->name;
	(*env)->value = new->value;
	(*env)->next = NULL;
}

/*
	parcourir env, si variable deja existante alors la remplacer
	autrement ajouter le nouveau noeud a la fin
*/
void	replace_node_env(t_variable **env, t_variable *new)
{
	t_variable	*current;
	t_variable	*prev;

	prev = NULL;
	if (!*env)
		return (add_new_node_to_null(env, new));
	current = *env;
	while (current)
	{
		if (!ft_strcmp(current->name, new->name))
			return (add_and_free_new_value(current, new));
		prev = current;
		current = current->next;
	}
	prev->next = (t_variable *)malloc(sizeof(t_variable));
	if (prev->next)
	{
		prev->next->next = NULL;
		prev->next->name = new->name;
		prev->next->value = new->value;
	}
}

/*
	parcourir export, si variable deja existante alors la remplacer
	autrement ajouter le nouveau noeud au bon endroit selon le tri insertion
*/
void	replace_node(t_variable **export, t_variable *new)
{
	t_variable	*prev;
	t_variable	*current;

	prev = NULL;
	current = *export;
	if (!*export)
	{
		*export = new;
		return ;
	}
	while (current)
	{
		if (!put_node(export, current, prev, new))
			return ;
		prev = current;
		current = current->next;
	}
	if (!current)
		prev->next = new;
}
