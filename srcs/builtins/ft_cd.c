/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:09:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 12:24:44 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	creates new node with name and value mallocated
	replace node in export
	if new node has value, replace node in env
*/
void	update_node(char *name, char *value)
{
	t_shell		*shell;
	t_variable	*node;

	shell = ft_get_shell(NULL);
	node = malloc(sizeof(t_variable));
	if (!node)
		return ;
	node->name = ft_strdup(name);
	node->value = ft_strdup(value);
	node->next = NULL;
	replace_node(&shell->export, node);
	if (node->value)
		replace_node_env(&shell->env, node);
}

static void	move_new_dir(char *new_path, char *buff)
{
	if (new_path)
		free(new_path);
	new_path = getcwd(buff, PATH_MAX);
	update_node("PWD", new_path);
}

static void	free_and_print_err(char *new_path, char *arg)
{
	if (new_path)
		free(new_path);
	ft_printfd(2, "cd: %s: %s\n", arg, strerror(errno));
	g_errno = 1;
}

void	get_new_path(char *name, char **new_path)
{
	*new_path = ft_get_var(name);
	if (!(**new_path))
	{
		ft_printfd(2, "cd: %s not set\n", name);
		free(*new_path);
		*new_path = NULL;
	}
}

/*
	getcwd : Get the current working directory
	chdir : change current dir, returns 0 if success
	Must update OLDPWD variable at first use of cd
	Must update PWD variable after chdir
*/
void	ft_cd(t_cmdli **cmdli)
{
	char	*new_path;
	char	*actual_path;
	char	buff[PATH_MAX];

	g_errno = 0;
	new_path = NULL;
	if (!(*cmdli)->cmd_args[1])
		get_new_path("HOME", &new_path);
	else if ((*cmdli)->cmd_args[1][0] == '-' && !(*cmdli)->cmd_args[1][1])
		get_new_path("OLDPWD", &new_path);
	else if ((*cmdli)->cmd_args[1])
		new_path = ft_strdup((*cmdli)->cmd_args[1]);
	actual_path = getcwd(buff, PATH_MAX);
	update_node("OLDPWD", actual_path);
	if (!new_path)
		return ;
	if (!chdir(new_path))
		move_new_dir(new_path, buff);
	else
		free_and_print_err(new_path, (*cmdli)->cmd_args[1]);
}
