#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (n == 0)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] == ps2[i]) && (i < n - 1))
		i++;
	if (i == n)
		return (ps1[i - 1] - ps2[i - 1]);
	return (ps1[i] - ps2[i]);
}
