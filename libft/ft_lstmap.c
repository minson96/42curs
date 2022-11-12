#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_mem;
	t_list	*now;

	if (lst == NULL || f == NULL)
		return (0);
	new_mem = NULL;
	while (lst)
	{
		if (!(now = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&now, del);
			return (NULL);
		}
		ft_lstadd_back(&new_mem, now);
		lst = lst->next;
	}
	return (new_mem);
}