typedef struct	s_list
{
	struct s_list	*next;
	void					*data;
}								t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;

	while (begin_list != NULL)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}