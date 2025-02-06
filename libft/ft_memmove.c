#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	psrc = (char *)src;
	pdest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (pdest > psrc)
	{
		while (len > 0)
		{
			pdest[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			pdest[i] = psrc[i];
	}
	return (pdest);
}
