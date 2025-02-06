#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	char	*mypointer;
	size_t	i;

	mypointer = pointer;
	i = 0;
	while (i < size)
	{
		mypointer[i] = value;
		i++;
	}
	return (mypointer);
}
