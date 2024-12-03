/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:32:45 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/12/02 19:26:22 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

typedef struct S_echoptions
{
	int	e;
	int	n;
	int	c;
}		t_echoptions;

static void	put_bs(char c, int fd)
{
	if (c == '\\')
		write(fd, "\\", 1);
	else if (c == 'a')
		write(fd, "\a", 1);
	else if (c == 'b')
		write(fd, "\b", 1);
	else if (c == 'e')
		write(fd, "\e", 1);
	else if (c == 'f')
		write(fd, "\f", 1);
	else if (c == 'r')
		write(fd, "\r", 1);
	else if (c == 't')
		write(fd, "\t", 1);
	else if (c == 'v')
		write(fd, "\v", 1);
}

static void	putstr_bs(char *s, t_echoptions *options, int fd)
{
	while (*s)
	{
		if (options->e && *s == '\\')
		{
			if (*(++s) == 'n')
			{
				if (options->c)
					write(fd, "$", 1);
				write(fd, "\n", 1);
			}
			else if (*s)
				put_bs(*s, fd);
			if (*s)
				++s;
		}
		else if (options->c && *s == '\n')
			write(fd, "$", 1);
		else if (*s)
			write(fd, s++, 1);
	}
}

char	**set_options(char **ss, t_echoptions *options)
{
	unsigned int	i;

	options->n = 0;
	options->e = 0;
	options->c = 0;
	while (*ss && (*ss)[0] == '-')
	{
		if (ft_strinset((*ss) + 1, "enc"))
			return (ss);
		i = 1;
		while ((*ss)[i] && ((*ss)[i] == 'e'
			|| (*ss)[i] == 'n' || (*ss)[i] == 'c'))
		{
			if ((*ss)[i] == 'e')
				options->e = 1;
			else if ((*ss)[i] == 'n')
				options->n = 1;
			else if ((*ss)[i] == 'c')
				options->c = 1;
			i++;
		}
		ss++;
	}
	return (ss);
}

void	print_while(t_cmdli **cmdli, char **ss, t_echoptions *options)
{
	while (*ss && *(ss + 1))
	{
		putstr_bs(*(ss++), options, (*cmdli)->fd_out);
		write((*cmdli)->fd_out, " ", 1);
	}
	putstr_bs(*ss, options, (*cmdli)->fd_out);
}

void	ft_echo(t_cmdli **cmdli)
{
	t_echoptions	options;
	char			**ss;

	ss = (*cmdli)->cmd_args;
	if (ss && *ss)
		ss++;
	g_errno = 0;
	if (!ss || !*ss)
	{
		write((*cmdli)->fd_out, "\n", 1);
		return ;
	}
	ss = set_options(ss, &options);
	if (*ss)
		print_while(cmdli, ss, &options);
	if (!options.n)
	{
		if (options.c)
			write((*cmdli)->fd_out, "$", 1);
		write((*cmdli)->fd_out, "\n", 1);
	}
}
