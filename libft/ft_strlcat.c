#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dlength;
	size_t	slength;

	dlength = ft_strlen(dest);
	slength = ft_strlen(src);
	i = 0;
	if (destsize == 0)
		return (slength);
	if (destsize < dlength)
		return (destsize + slength);
	while (src[i] && dlength + i < destsize - 1)
	{
		dest[dlength + i] = src[i];
		i++;
	}
	dest[dlength + i] = 0;
	return (dlength + slength);
}
