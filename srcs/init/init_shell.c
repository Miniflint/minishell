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

#include "minishell.h"

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
	free(s2);
	return (new_str);
}

char	**change_env_str(char **env_str)
{
	char	**ret;
	char	*str;

	ret = env_str;
	while (*env_str)
	{
		if (ft_strncmp(*env_str, "SHLVL=", 6) == 0)
			break ;
		env_str++;
	}
	str = *env_str;
	while (*str && *str != '=')
		str++;
	str++;
	str = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(str) + 1));
	*env_str = str;
	return (ret);
}

void	init_shell(t_shell *shell, char **m_env)
{
	shell->str_env = m_env;
	shell->str_env = change_env_str(shell->str_env);
	shell->env = init_env(shell->str_env);
	shell->export = init_export();
	shell->if_sig = 1;
}