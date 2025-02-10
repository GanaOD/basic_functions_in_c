#include <stdio.h>
#include <stdlib.h>

typedef	struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

void	int_doubler(void *n)
{
	int *num = (int *)n;
	*num = *num * 2;
}

// ... [previous includes and typedefs remain the same]

void	cleanup_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int		main(void)
{
	t_list *pt_a = malloc(sizeof(t_list));
	int	n_a = 0;
	pt_a->data = &n_a;
	pt_a->next = NULL;  // More idiomatic than 0 for pointers

	t_list *pt_b = malloc(sizeof(t_list));
	int	n_b = 3;
	pt_b->data = &n_b;
	pt_b->next = NULL;

	t_list *pt_c = malloc(sizeof(t_list));
	int	n_c = 4;
	pt_c->data = &n_c;
	pt_c->next = NULL;

	pt_a->next = pt_b;
	pt_b->next = pt_c;

	// Print original values
	t_list *cur = pt_a;
	while (cur)
	{
		printf("%d, ", *(int *)(cur->data));
		cur = cur->next;
	}
	printf("\n");

	ft_list_foreach(pt_a, int_doubler);

	// Print modified values
	cur = pt_a;
	while (cur)
	{
		printf("%d, ", *(int *)(cur->data));
		cur = cur->next;
	}
	printf("\n");

	cleanup_list(pt_a);  // Clean up allocated memory
	return (0);
}


/*
// Combining operations:

void print_and_double(void *n)
{
    int *num = (int *)n;
    printf("Current value: %d\n", *num);  // Print
    *num = *num * 2;                      // Double
}

*/
