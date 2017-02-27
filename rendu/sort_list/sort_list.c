#include "list.h"

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp = lst;
	int		swap;

	while (tmp && tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data))
			tmp = tmp->next;
		else
		{
			swap = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = swap;
			tmp = lst;
		}
	}
	return (lst);
}
