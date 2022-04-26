#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	if (!lst)
		return (0);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (0);
	new = ptr;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!(ptr->next))
		{
			ft_lstclear(&ptr, del);
			return (0);
		}
		lst = lst->next;
		ptr = ptr->next;
	}
	ptr->next = 0;
	return (new);
}
