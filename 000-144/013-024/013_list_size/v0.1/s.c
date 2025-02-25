typedef struct	s_list
{
	struct s_list	*next;
	void					*data;
}								t_list;

int	list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);

	int	node_count = 0;

	while (begin_list)
	{
		node_count++;
		begin_list = begin_list->next;
	}

	return (node_count);
}