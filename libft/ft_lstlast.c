#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
