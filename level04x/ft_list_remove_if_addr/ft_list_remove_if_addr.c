typedef struct	s_list
{
	struct s_list		*next;
	void						*data;
}									t_list;

void	ft_list_remove_if_addr(t_list **list_head, void *addr_ref)
{
	// param check
	if (!list_head)
		return ;
	
	// recursion base case
	if (!*list_head)
		return ;

	// let recursion wind down to tail
	ft_list_remove_if_addr(&((*list_head)->next), addr_ref);

	// whilst unwinding:
	// logic: comparison, relinking, removal if necessary
	if (*list_head == addr_ref)
	{
		t_list	*to_free = *list_head;
		*list_head = (*list_head)->next;
		free (to_free);
	}
}

/*
Uses recursion to reach the tail
Processes nodes during unwinding
Creates temporary variable only when needed for freeing
Properly handles pointer relinking
Includes necessary parameter checks
*/