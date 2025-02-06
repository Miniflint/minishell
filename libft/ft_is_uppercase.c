#include "libft.h"
#include <stdio.h>

int	ft_is_uppercase(char *str)
{
	printf("dans ft_is_uppercase\n");
	if (!str)
		return (0);
	while (*str)
	{
		if (*str <= 'A' || *str >= 'Z')
			return (0);
		++str;
	}
	return (1);
}
