#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*temp;

	// 1st traversal
	// Handling nodes at start of list
	// Special handling needed: removing 1st node means updating list's header ptr
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free (temp);
	}

	current = *begin_list;

	// 2nd traversal phase
	// Handling nodes in middle / end
	// Look-ahead approach instead of direct analysis
	while (current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			temp = (current->next);
			current->next = temp->next;
			free (temp);
		}
		else
			current = current->next;
	}

}
