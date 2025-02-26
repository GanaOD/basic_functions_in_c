void	sort_int_tab(int *tab, unsigned int size)
{
	int	i = 1; // start with 2nd element
	int	j;		// will be used to find correct position
	int	current_value; // to temporarily store value that will be inserted

	while (i < size) // loop processes each element from index 1 to end of array
	{
		current_value = tab[i]; // always store current value, even if it won't be moved (easier implementation)
		j = i;

		while (j > 0 && tab[j - 1] > current_value) // crucial comparison, determines if shifting needed
		{
			tab[j] = tab[j - 1]; // "shifting to the right" as I move backward through sorted portion to make room for current value
			j--;
		}

		tab[j] = current_value;
		i++;
	}
}

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

void print_array(int *arr, unsigned int size)
{
    unsigned int i = 0;
    
    printf("[");
    while (i < size)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
        i++;
    }
    printf("]\n");
}

int main(void)
{
    // Test case 1: Already sorted array
    int test1[] = {1, 2, 3, 4, 5};
    printf("Test 1 - Before: ");
    print_array(test1, 5);
    sort_int_tab(test1, 5);
    printf("Test 1 - After:  ");
    print_array(test1, 5);
    
    // Test case 2: Reverse sorted array
    int test2[] = {5, 4, 3, 2, 1};
    printf("\nTest 2 - Before: ");
    print_array(test2, 5);
    sort_int_tab(test2, 5);
    printf("Test 2 - After:  ");
    print_array(test2, 5);
    
    // Test case 3: Array with duplicates
    int test3[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    printf("\nTest 3 - Before: ");
    print_array(test3, 9);
    sort_int_tab(test3, 9);
    printf("Test 3 - After:  ");
    print_array(test3, 9);
    
    // Test case 4: Single element array
    int test4[] = {42};
    printf("\nTest 4 - Before: ");
    print_array(test4, 1);
    sort_int_tab(test4, 1);
    printf("Test 4 - After:  ");
    print_array(test4, 1);
    
    // Test case 5: Empty array (size 0)
    int test5[0];
    printf("\nTest 5 - Empty array (size 0)\n");
    sort_int_tab(test5, 0);
    printf("Test 5 - After: No output expected for empty array\n");
    
    return 0;
}