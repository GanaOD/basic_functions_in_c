void	sort_int_tab(int *tab, unsigned int size)
{
    int	i = 1;          // Start with 2nd element because a single-element array is already sorted
    int	j;              // Index used to scan backward through the sorted portion to find correct insertion position
    int	current_value;  // Temporary storage for the current element being inserted into the sorted portion
    
    while (i < size)    // Process each unsorted element (everything from index 1 to size-1)
    {
        current_value = tab[i]; // Save the current element that needs to be inserted into the sorted portion
        j = i;                   // Start comparison from the current element's position
        
        // Move backward through the sorted portion (0 to i-1)
        // and shift elements right as long as they're greater than current_value
        while (j > 0 && tab[j - 1] > current_value)
        {
            tab[j] = tab[j - 1]; // Shift this element right to make space for current_value
            j--;                  // Move to the previous element to continue comparison
        }
        
        tab[j] = current_value;   // Insert current_value at its correct position in the sorted portion
        
        i++;                      // Move to the next unsorted element
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