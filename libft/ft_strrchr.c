#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = (ft_strlen(s));
	while (slength >= 0)
	{
		if (s[slength] == (char)c)
			return ((char *)s + slength);
		slength--;
	}
	return (NULL);
}
