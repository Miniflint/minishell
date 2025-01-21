#include "minishell.h"

char	*ft_strjoin_export(const char *restrict s1, const char *restrict s2)
{
	int		i;
	int		j;
	char	*new_char;

	new_char = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new_char)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			new_char[i] = s1[i];
	new_char[i++] = '=';
	j = 0;
	if (s2)
		while (s2[j])
			new_char[i++] = s2[j++];
	new_char[i] = 0;
	return (new_char);
}

void	__update_env(void)
{
	t_variable	*root;
	int			i;
	t_shell		*shell;
	char		**new_env;

	shell = ft_get_shell(NULL);
	root = shell->export;
	i = 0;
	while (root)
	{
		i++;
		root = root->next;
	}
	new_env = malloc((i + 1) * sizeof(char *));
	root = shell->export;
	i = 0;
	while (root)
	{
		new_env[i] = ft_strjoin_export(root->name, root->value);
		i++;
		root = root->next;
	}
	free_tab(shell->str_env);
	new_env[i] = 0;
	shell->str_env = new_env;
}

char	**ft_get_str_env(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->str_env);
}
