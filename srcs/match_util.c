#include "minishell.h"

void	add_tok_unl(t_cmdli *cmdli, char *name, int *is_first, int dir_or_file)
{
	if (name)
	{
		if (*is_first)
		{
			*is_first = 0;
			free(cmdli->tok_cursor->token);
			cmdli->tok_cursor->token = dup_file_name(name, dir_or_file);
			if (!cmdli->tok_cursor->token)
				return ;
		}
		else
		{
			if (cmdli->tok_cursor->type == ARG
				|| cmdli->tok_cursor->type == CMD)
				new_unlist(cmdli, dup_file_name(name, dir_or_file), ARG);
			else
				ft_printfd(2, "ambigous redirect\n");
		}
	}
}

char	*dup_file_name(char *name, int dir_or_file)
{
	char	*ret;
	int		i;

	ret = malloc((ft_strlen(name) + 1 + dir_or_file) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (name[i])
	{
		ret[i] = name[i];
		++i;
	}
	if (dir_or_file)
		ret[i++] = '/';
	ret[i] = '\0';
	return (ret);
}

int	skip_add_path(char f_p[PATH_MAX], char *d_name, char *base_path, int depth)
{
	if (!ft_strcmp(d_name, ".") || !ft_strcmp(d_name, ".."))
		return (1);
	if (depth || (!depth && ft_strcmp(base_path, ".")))
	{
		ft_strcpy(f_p, base_path);
		if (depth)
			ft_strcat(f_p, "/");
		ft_strcat(f_p, d_name);
	}
	else
		ft_strcpy(f_p, d_name);
	return (0);
}

int	get_depth(int depth, int max_depth)
{
	if (depth > max_depth)
		return (max_depth);
	return (depth);
}

void	assign_info_base_path(t_match *info, char *separators)
{
	int		i;
	char	*path;

	i = 0;
	path = get_path_sep(info, separators);
	if (!path)
		path = ft_strdup(".");
	if (info->absolute_path)
		info->base_path = ft_strjoin("/", path);
	else
		info->base_path = ft_strdup(path);
	free(path);
	while (info->sep[i])
		i++;
	info->max_depth_file = i - 1;
	info->max_depth_dir = i - 1;
	if (i > 1)
		info->max_depth_dir = i - 2;
	printf("%s - %d - %d - %d - %d\n", info->base_path, i, info->infinite, info->max_depth_dir, info->max_depth_file);
}
