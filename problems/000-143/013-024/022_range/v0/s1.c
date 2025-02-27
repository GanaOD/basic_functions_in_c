#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len = 0;

	if (start <= end)
		len = end - start + 1;
	else if (start > end)
		len = start - end + 1;

	int	*result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);

	int	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			result[i] = start;
			i++, start++;
		}
	}
	else if (start == end)
		result[i] = start;
	else if (start > end)
	{
		while (start >= end)
		{
			result[i] = start;
			i++, start--;
		}
	}
	return (result);
}

#include <stdio.h>

int *ft_range(int start, int end);

void print_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(void)
{
    int *arr;
    int size;
    
    // Test case 1: Ascending range
    arr = ft_range(1, 3);
    size = 3;
    printf("ft_range(1, 3): ");
    print_array(arr, size);
    free(arr);
    
    // Test case 2: Negative to positive
    arr = ft_range(-1, 2);
    size = 4;
    printf("ft_range(-1, 2): ");
    print_array(arr, size);
    free(arr);
    
    // Test case 3: Single value
    arr = ft_range(0, 0);
    size = 1;
    printf("ft_range(0, 0): ");
    print_array(arr, size);
    free(arr);
    
    // Test case 4: Descending range
    arr = ft_range(0, -3);
    size = 4;
    printf("ft_range(0, -3): ");
    print_array(arr, size);
    free(arr);
    
    // Test case 5: Large range
    arr = ft_range(-5, 5);
    size = 11;
    printf("ft_range(-5, 5): ");
    print_array(arr, size);
    free(arr);
    
    return 0;
}