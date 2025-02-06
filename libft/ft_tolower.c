#include "libft.h"

int	ft_tolower(int c)
{
	if (c < 'A' && c > 'Z')
		return (c);
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
