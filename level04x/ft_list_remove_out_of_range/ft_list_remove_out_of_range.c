typedef struct	s_list
{
	struct s_list		*next;
	int							data;
}	t_list;

void	ft_list_remove_out_of_range(t_list **begin_list, int min, int max)
{
	if (!begin_list) // invalid param
		return ;

	if (!*begin_list)
		return ;			// recursion base case: last node of list

	// recursion through to end
	ft_list_remove_out_of_range(&((*begin_list)->next), min, max);
	// passing address of next pointer of each node

	// whilst unwinding, check each node's data value against min & max range
	if ((*begin_list)->data < min || (*begin_list)->data > max)
	{
		t_list  *to_free = *begin_list;           // 1. Save node to free
    *begin_list = (*begin_list)->next;        // 2. Relink
    free(to_free);                            // 3. Free
	}
}