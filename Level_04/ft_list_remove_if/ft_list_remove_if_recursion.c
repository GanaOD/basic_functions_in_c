include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	// Base case
	if (begin_list == NULL || *begin_list == NULL)
    	return;

	// Handle current node if match
	if (cmp(cur->data, data_ref) == 0)
	{
    	*begin_list = cur->next;
    	free(cur);
    	ft_list_remove_if(begin_list, data_ref, cmp); // Recurse on new head
	}

	// Recurse on rest of list
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

// See https://github.com/JCluzet/42_EXAM/blob/main/.subjects/STUD_PART/exam_02/need_correction/ft_list_remove_if/ft_list_remove_if.c
