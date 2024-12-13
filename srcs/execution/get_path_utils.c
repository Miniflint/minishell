#include "minishell.h"

int	ft_strchr_path(char *s, char *path, int c)
{
	int		i;

	if (!path)
		return (1);
	if (!*path)
	{
		free(path);
		return (1);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			free(path);
			return (1);
		}
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}
