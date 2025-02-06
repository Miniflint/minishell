#include "libft.h"

int	ft_strnotinset(char *str, char *set)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (set[i] && set[i] != *str)
			i++;
		if (set[i])
			return (0);
		str++;
	}
	return (1);
}
