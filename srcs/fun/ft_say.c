/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_say.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:27:43 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:27:44 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

// void	print_minishell(void)
// {#b
// 	ft_printfd(1, "#/g\n\n ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ████");
// 	ft_printfd(1, "██  ██░ ██ ▓█████  ██▓     ██▓    \n");
// 	ft_printfd(1, "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██   ");
// 	ft_printfd(1, " ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    \n");
// 	ft_printfd(1, "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄");
// 	ft_printfd(1, "   ▒██▀▀██░▒███   ▒██░    ▒██░    \n");
// 	ft_printfd(1, "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ");
// 	ft_printfd(1, "██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    \n");
// 	ft_printfd(1, "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒█████");
// 	ft_printfd(1, "█▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒\n");
// 	ft_printfd(1, "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ");
// 	ft_printfd(1, "▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n");
// 	ft_printfd(1, "░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ");
// 	ft_printfd(1, "░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░\n");
// 	ft_printfd(1, "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ");
// 	ft_printfd(1, "░   ░  ░░ ░   ░     ░ ░     ░ ░   \n");
// 	ft_printfd(1, "       ░    ░           ░  ░        ");
// 	ft_printfd(1, "░   ░  ░  ░   ░  ░    ░  ░    ░  ░\n\n\n#0");
// }

void	print_and_say(char *print, char *say)
{
	ft_printfd(1, "%s\n", print);
	ft_say(say);
	wait(NULL);
}

void	say_error(char *path, char **strs)
{
	if (path)
		free(path);
	if (strs)
		free_tab(strs);
}

void	exec_say(char *path, char **strs, int pid)
{
	if (!pid)
	{
		execve(path, strs, ft_get_str_env());
		say_error(path, strs);
		exit(1);
	}
	else
		say_error(path, strs);
}

void	ft_say(char *str)
{
	char	**strs;
	char	*path;
	int		pid;

	if (!ft_get_shell(NULL)->say)
		return ;
	strs = malloc(3 * sizeof(char *));
	if (!strs)
		return ;
	strs[0] = ft_strdup("say");
	strs[1] = ft_strdup(str);
	strs[2] = NULL;
	path = get_absolute_path("say", ft_get_var("PATH"));
	if (!path)
	{
		free_tab(strs);
		return ;
	}
	pid = fork();
	if (pid == -1)
		return (say_error(path, strs));
	exec_say(path, strs, pid);
}
