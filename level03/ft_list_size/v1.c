typedef struct		s_list
{
	struct s_list		*next;
	void						*data;
}									t_list;
// t_list struct represents single node in linked list
// 		with ptr to next node & ptr to data

// ft_list_size fn. receives ptr to 1st node

int	ft_list_size(t_list *begin_list)
{
	int	count = 0;

	// at each iteration:
	//		count current node
	//		move to next node 
	while (begin_list) // termination pt: NULL
	{
		count++; // count current node before moving to next one
		begin_list = begin_list->next;
	}
	return (count);
}
