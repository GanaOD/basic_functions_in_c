typedef	struct s_list
{
	struct s_list	*next;
	void					*data;
}	t_list;


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list) // while ptr to struct is a valid ptr, i.e. hasn't reached NULL termination
	{
		f(begin_list->data); // apply function to each node's data
		begin_list = begin_list->next; // "moves" begin_list ptr to next node in list
	}
}