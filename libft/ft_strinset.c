#include "libft.h"

int	ft_strinset(char *str, char *set)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (set[i] && set[i] != *str)
			i++;
		if (!set[i])
			return (1);
		str++;
	}
	return (0);
}
