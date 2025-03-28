/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmdli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:26 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:18 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_file(t_file **files)
{
	unsigned int	i;

	i = 0;
	if (!files)
		return ;
	while (files[i])
	{
		free(files[i]->name);
		free(files[i++]);
	}
	free(files);
}

void	free_unlist(t_cmdli *cmdli)
{
	t_unlist	*tmp;

	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		tmp = cmdli->tok_cursor;
		cmdli->tok_cursor = cmdli->tok_cursor->next;
		free(tmp);
	}
	cmdli->tokens = NULL;
}

static void	free_unlist_all(t_cmdli *cmdli)
{
	t_unlist	*tmp;

	cmdli->tok_cursor = cmdli->tokens;
	while (cmdli->tok_cursor)
	{
		tmp = cmdli->tok_cursor;
		cmdli->tok_cursor = cmdli->tok_cursor->next;
		if (tmp->token)
			free(tmp->token);
		free(tmp);
	}
	cmdli->tokens = NULL;
}

//store_tokens put NULL to unlist tokens;
void	free_content(t_cmdli *cmdli)
{
	if (cmdli->tokens)
		free_unlist_all(cmdli);
	if (cmdli->cmd_args)
		free_tab(cmdli->cmd_args);
	if (cmdli->pipe_in)
	{
		close(cmdli->pipe_in[0]);
		close(cmdli->pipe_in[1]);
		free(cmdli->pipe_in);
	}
	if (cmdli->file_in)
		free_tab(cmdli->file_in);
	if (cmdli->file_out)
		free_file(cmdli->file_out);
}

void	free_cmdli(t_cmdli **cmdli)
{
	t_cmdli	*tmp;

	if (!cmdli || !*cmdli)
		return ;
	*cmdli = cmdli_first(*cmdli);
	while (*cmdli)
	{
		free_content(*cmdli);
		tmp = *cmdli;
		*cmdli = (*cmdli)->next;
		free(tmp);
	}
}
