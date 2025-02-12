#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flood_fill.h"

// Utility function to create a 2D array from string array
char **make_area(char **zone, int rows)
{
	char **area;
	int i;

	area = malloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		area[i] = strdup(zone[i]);
		i++;
	}
	return (area);
}

// Utility function to print the grid
void print_grid(char **area, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%c ", area[i][j]);
		printf("\n");
	}
	printf("\n");
}

// Free the allocated memory
void free_area(char **area, int rows)
{
	for (int i = 0; i < rows; i++)
		free(area[i]);
	free(area);
}

int main(void)
{
	// Test Case 1: Basic fill
	printf("Test 1: Basic fill pattern\n");
	char *zone1[] = {
		"11111",
		"10001",
		"10001",
		"10001",
		"11111"
	};
	t_point size1 = {5, 5};
	t_point begin1 = {1, 1};
	char **area1 = make_area(zone1, 5);

	printf("Before flood_fill:\n");
	print_grid(area1, size1.y, size1.x);
	flood_fill(area1, size1, begin1);
	printf("After flood_fill:\n");
	print_grid(area1, size1.y, size1.x);
	free_area(area1, size1.y);

	// Test Case 2: Complex pattern
	printf("Test 2: Complex pattern\n");
	char *zone2[] = {
		"10101",
		"01110",
		"10101",
		"01110",
		"10101"
	};
	t_point size2 = {5, 5};
	t_point begin2 = {2, 2};
	char **area2 = make_area(zone2, 5);

	printf("Before flood_fill:\n");
	print_grid(area2, size2.y, size2.x);
	flood_fill(area2, size2, begin2);
	printf("After flood_fill:\n");
	print_grid(area2, size2.y, size2.x);
	free_area(area2, size2.y);

	// Test Case 3: Edge fill
	printf("Test 3: Edge fill\n");
	char *zone3[] = {
		"11111",
		"11111",
		"11111",
		"11111"
	};
	t_point size3 = {5, 4};
	t_point begin3 = {0, 0};
	char **area3 = make_area(zone3, 4);

	printf("Before flood_fill:\n");
	print_grid(area3, size3.y, size3.x);
	flood_fill(area3, size3, begin3);
	printf("After flood_fill:\n");
	print_grid(area3, size3.y, size3.x);
	free_area(area3, size3.y);

	return (0);
}
