#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	char	*psrc;

	psrc = (char *)src;
	i = 0;
	if (destsize == 0)
		return (ft_strlen(psrc));
	while (psrc[i] && i < (destsize - 1))
	{
		dest[i] = psrc[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(psrc));
}
