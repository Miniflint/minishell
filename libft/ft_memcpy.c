#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	pdest = (char *)dest;
	psrc = (char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (pdest);
}
