/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <trgoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:29:01 by trgoel            #+#    #+#             */
/*   Updated: 2025/03/21 19:29:10 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 struct dirent {
    ino_t	d_ino; //file number of this entry
    __uint16_t	d_reclen; //length of the entry record
    __uint8_t	d_type; // FILE TYPE
    __uint8_t	d_namlen; // LEN NAME
    char	d_name[256 + 1]; //name of the file
 };
*/
// typedef struct dirent t_dir;

int	match(char *s1, char *s2, char quote)
{
	if (quote && *s1 == quote)
	{
		quote = 0;
		s1++;
	}
	else if (!quote && (*s1 == '\'' || *s1 == '\"'))
		quote = *(s1++);
	if (!quote && ((*s1 == '*' && !*(s1 + 1)) || (!*s1 && !*s2)))
		return (1);
	else if (!*s2)
		return (0);
	else if (!quote && *s1 == '*' && (match(s1, s2 + 1, quote)
			|| match(s1 + 1, s2, quote)))
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1, quote));
	return (0);
}

void	if_rec_dir(t_cmdli *cmdli, t_p_match *p, t_match info, char *get_name)
{
	t_match	sub_info;

	sub_info = info;
	if ((info.infinite == -1 || p->depth <= info.max_depth_file)
		&& match(info.sep[get_depth(p->depth, info.max_depth_file)],
			info.d_name, 0))
	{
		sub_info.dir_ptr = opendir(info.full_path);
		if (!sub_info.dir_ptr)
			return ;
		sub_info.base_path = info.full_path;
		add_tok_unl(cmdli, get_name, p->is_first, info.dir_or_file);
		rec_dir(sub_info, p->depth + 1, cmdli, p->is_first);
		closedir(sub_info.dir_ptr);
	}
}

void	rec_dir(t_match info, int depth, t_cmdli *cmdli, int *is_first)
{
	t_dir		*idk;
	t_p_match	param;

	while (1)
	{
		idk = readdir(info.dir_ptr);
		if (!idk)
			break ;
		if (skip_add_path(info.full_path, idk->d_name, info.base_path, depth))
			continue ;
		if (((info.full_path[0] == '.' && info.full_path[1] != '.'
					&& info.full_path[1] != '/') && info.sep[0][0] != '.')
					|| (info.sep[0][0] == '.' && info.full_path[0] != '.'))
			continue ;
		info.d_name = (char *)idk->d_name;
		param.depth = depth;
		param.is_first = is_first;
		if (idk->d_type == DT_DIR)
			if_rec_dir(cmdli, &param, info, info.full_path);
		else if ((info.infinite == -1 || depth == info.max_depth_file)
			&& !info.dir_or_file
			&& match(info.sep[info.max_depth_file], info.d_name, 0))
			add_tok_unl(cmdli, info.full_path, is_first, info.dir_or_file);
	}
}

char	*get_path_sep(t_match *info, char *separators)
{
	int		i;
	int		j;
	char	*path;

	info->sep = ft_split(separators, '/');
	if (!info->sep)
		return (NULL);
	info->sep_base_ptr = info->sep;
	i = -1;
	path = NULL;
	while (info->sep[++i])
	{
		j = 0;
		while (info->sep[i][j])
		{
			if (idk_anymore(&info->sep, i, j))
				return (path);
			j++;
		}
		if (info->sep[i][j] != '*')
			path = join_path_free(info, path, i);
	}
	return (path);
}

void	check_open_dir(char *separators, t_cmdli *cmdli)
{
	t_match	info;
	int		param;
	int		i;

	parse_param_recdir(separators, &info, &param);
	assign_info_base_path(&info, separators);
	if (info.infinite != -1 || (info.infinite == -1 && info.max_depth_dir == 0))
	{
		info.dir_ptr = opendir(info.base_path);
		if (!info.dir_ptr)
		{
			ft_printfd(2, "could not open the base dir, match.c ligne 131\n");
			return ;
		}
		rec_dir(info, 0, cmdli, &param);
		free(info.base_path);
		closedir(info.dir_ptr);
	}
	i = 0;
	while (info.sep[i])
		free(info.sep[i++]);
	free(info.sep_base_ptr);
}
