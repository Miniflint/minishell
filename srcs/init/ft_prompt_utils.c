/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:28:17 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:28:17 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_git_branch(char *git_path)
{
	int		fd;
	int		rd;
	char	buff[500];

	fd = open(git_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	rd = read(fd, buff, 500);
	close(fd);
	buff[--rd] = 0;
	while (rd && buff[rd] != '/')
		rd--;
	return (ft_strdup(1 + rd + buff));
}

void	git_prompt(char *prompt, const char **prompt_elem,
			char *git_path, char *cwd)
{
	unsigned int	i;
	unsigned int	j;
	char			*branch_name;

	i = 0;
	j = 0;
	branch_name = get_git_branch(git_path);
	while (prompt_elem[i])
	{
		prompt_cat(prompt, prompt_elem[i], &j);
		if (!i)
		{
			prompt_cat(prompt, "\033[3m", &j);
			prompt_cat(prompt, cwd, &j);
		}
		else if (i == 2)
			prompt_cat(prompt, branch_name, &j);
		i++;
	}
	prompt[j] = 0;
	if (branch_name)
		free(branch_name);
}

void	none_git_prompt(char *prompt, const char **prompt_elem, char *cwd)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (prompt_elem[i])
	{
		if (i == 2)
		{
			i += 2;
			if (!prompt_elem[i])
			{
				prompt[j] = 0;
				return ;
			}
		}
		prompt_cat(prompt, prompt_elem[i], &j);
		if (!i)
		{
			prompt_cat(prompt, "\033[3m", &j);
			prompt_cat(prompt, cwd, &j);
		}
		i++;
	}
	prompt[j] = 0;
}

char	*check_git_path(char *cwd, char *file, int cwd_len)
{
	char			*ret;
	unsigned int	i;

	ret = malloc((cwd_len + 11) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*cwd)
		ret[i++] = *(cwd++);
	while (*file)
		ret[i++] = *(file++);
	ret[i] = 0;
	if (!access(ret, R_OK))
		return (ret);
	free(ret);
	return (NULL);
}

char	*get_git_path(char *cwd, char *file)
{
	int		cwd_len;
	char	*ret;

	if (!cwd)
		return (NULL);
	cwd_len = ft_strlen(cwd);
	ret = NULL;
	while (1)
	{
		ret = check_git_path(cwd, file, cwd_len);
		if (ret || !cwd_len)
			break ;
		while (cwd_len && cwd[cwd_len] != '/')
			--cwd_len;
		cwd[cwd_len] = '\0';
	}
	free(cwd);
	return (ret);
}
