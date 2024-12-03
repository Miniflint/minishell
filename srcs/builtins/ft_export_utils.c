/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:33:17 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/05 11:27:11 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	returns 1 if c is not a valid identifier or doesnt content any =
	writes only once the message, not for every bad char
*/
int	ft_is_alphanum_(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

int	check_non_authorized_names(char *str, int *i)
{
	unsigned int	j;

	j = 0;
	if (!(str[0] <= '9' && str[0] >= '0'))
		while (str[j] && ft_is_alphanum_(str[j]))
			++j;
	if (!j || (str[j] && str[j] != '='))
	{
		ft_printfd(2, "export: `%s': not a valid identifier\n", str);
		g_errno = 1;
		++(*i);
		return (1);
	}
	return (0);
}

void	free_content_node_and_print(t_cmdli *cmdli, t_variable *new, int i)
{
	if (ft_strcmp(cmdli->cmd_args[i], "=") != 0)
	{
		ft_printfd(2, "#+wminishell#0: export: `%s': #/r%s#0\n",
			cmdli->cmd_args[i], "not a valid identifier");
	}
	free(new->name);
	free(new->value);
	free(new);
	g_errno = 1;
}

/*
	print la liste chainee stockee dans la struc shell.export
	print est different si on n'a pas de valeur (premier OLDPWD par exemple)
	pointeur null : pas les guillemets
	chaine vide : oui les guillemets
	no  '='	: value is null
	yes '='	: value is empty string
*/
void	print_export(t_cmdli **cmdli)
{
	t_variable	*export;

	export = ft_get_export();
	if (!export)
		return ;
	while (export)
	{
		if (!export->value)
			ft_printfd((*cmdli)->fd_out, "declare -x %s\n", export->name);
		else
			ft_printfd((*cmdli)->fd_out, "declare -x %s=\"%s\"\n",
				export->name, export->value);
		export = export->next;
	}
	return ;
}
