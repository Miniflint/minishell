/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:50 by hrolle            #+#    #+#             */
/*   Updated: 2024/12/06 17:39:42 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	close_pipe(int *pipe)
{
	if (pipe)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
	return (0);
}

int	close_and_free(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close_pipe(cmdli->pipe_in);
	if (cmdli->cmd)
	{
		free(cmdli->cmd);
		cmdli->cmd = NULL;
	}
	if (cmdli->file_in)
	{
		free_tab(cmdli->file_in);
		cmdli->file_in = NULL;
	}
	if (cmdli->file_out)
	{
		free_file(cmdli->file_out);
		cmdli->file_out = NULL;
	}
	return (0);
}

char *ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	return (new_str);
}

void	change_env_str(void)
{
	char	**env_str;
	char	*str;

	env_str = ft_get_str_env();
	while (*env_str)
	{
		if (ft_strncmp(*env_str, "SHLVL=", 6) == 0)
			break ;
		(*env_str)++;
	}
	str = *env_str;
	while (*str && *str != '=')
		str++;
	str++;
	str = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(str) + 1));
	*env_str = str;
}

int	exec_cmd(t_cmdli *cmdli)
{
	if (cmdli->pipe_out && cmdli->pipe_out[0] == -1
		&& cmdli->pipe_out[1] == -1)
		if (pipe(cmdli->pipe_out) == -1)
			return (return_error(errno, NULL));
	cmdli->cmd = get_absolute_path(cmdli->cmd, ft_get_var("PATH"));
	if (!cmdli->cmd)
		return (1);
	cmdli->pid = fork();
	if (cmdli->pid == -1)
		return (return_error(errno, NULL));
	else if (!cmdli->pid)
	{
		set_redirection(cmdli);
		change_env_str();
		if (execve(cmdli->cmd, cmdli->cmd_args, ft_get_str_env()) == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s: #/r%s#0\n",
				cmdli->cmd_args[0], strerror(g_errno));
			exit(g_errno);
		}
	}
	return (close_and_free(cmdli));
}
