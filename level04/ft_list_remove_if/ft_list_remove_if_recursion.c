include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (!begin_list || !*begin_list)
        return;
		// Defensive programming: !begin_list protects against NULL pointer passed as argument
		// Base case: !*begin_list catches when end of list reached
        
    t_list *current = *begin_list;
    
    // Recurse first - process rest of list
    ft_list_remove_if(&(current->next), data_ref, cmp);
    
    // Now process current node
    if (cmp(current->data, data_ref) == 0)
    {
        *begin_list = current->next;  // Relink before freeing
        free(current);                // Free node
    }
}

