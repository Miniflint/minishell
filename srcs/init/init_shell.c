#include "minishell.h"

/*
void	init_shell(t_shell *shell, char **m_env)
{
	shell->env = init_env(m_env);
	shell->export = init_export();
	shell->str_env = m_env;
	shell->if_sig = 1;
}
*/

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	free(s2);
	return (new_str);
}

char	**copy_change_shlvl(char **env_str)
{
	char	**ret;
	int		i;
	int		j;
	char	*str;

	ret = malloc(sizeof(char *) * (ft_strslen(env_str) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (env_str[++i])
	{
		if (ft_strncmp(env_str[i], "SHLVL=", 6) == 0)
		{
			str = env_str[i] + 6;
			ret[i - j] = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(str) + 1));
		}
		else if (ft_strncmp(env_str[i], "OLDPWD=", 7) == 0)
			j = 1;
		else
			ret[i - j] = ft_strdup(env_str[i]);
	}
	ret[i - j] = 0;
	return (ret);
}

void	init_shell(t_shell *shell, char **m_env)
{
	(void)ft_get_shell(shell);
	shell->str_env = copy_change_shlvl(m_env);
	shell->env = init_env(shell->str_env);
	shell->export = init_export();
	shell->if_sig = 1;
}
