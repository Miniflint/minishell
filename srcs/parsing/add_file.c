/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:06 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:24 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	file_rdi(t_cmdli *cmdli, char *file)
{
	char	**tmp;

	tmp = cmdli->file_in;
	cmdli->file_in = ft_strsjoin(file, tmp);
	if (tmp)
		free(tmp);
	if (!cmdli->file_in)
		return (1);
	return (0);
}

int	file_rdo(t_cmdli *cmdli, char *file, t_type type)
{
	t_file	**tmp;

	tmp = cmdli->file_out;
	cmdli->file_out = file_join(file, tmp, type);
	if (tmp)
		free(tmp);
	if (!cmdli->file_out)
		return (1);
	return (0);
}

int	add_file(t_cmdli *cmdli, char *file, t_type type)
{
	if (type == RDI)
		return (file_rdi(cmdli, file));
	else if (type == RDO)
		return (file_rdo(cmdli, file, RDO));
	else if (type == RDOA)
		return (file_rdo(cmdli, file, RDOA));
	return (0);
}
