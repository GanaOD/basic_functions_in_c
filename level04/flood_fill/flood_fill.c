#include "flood_fill.h"

// Recursively fills connected region with 'F' chars
void	fill(char **tab, t_point size, char original_char, int curr_row, int curr_col)
{
	// Base case 1: return if not within grid boundaries
	if (curr_row < 0 || curr_col < 0 || curr_row >= size.y || curr_col >= size.x)
		return ;

	// Base case 2: return if current cell already filled ('F') or doesn't match original char
	// Prevents infinite recursion & ensures only filling connected region
	if (tab[curr_row][curr_col] == 'F' || tab[curr_row][curr_col] != original_char)
		return ;

	// Mark current cell as filled
	tab[curr_row][curr_col] = 'F';

	// Recursively fill all adjacent cells: DFS
	// Creates a "flood" effect, spreading to all connected matching cells
	fill(tab, size, original_char, curr_row - 1, curr_col);  // Up
    fill(tab, size, original_char, curr_row + 1, curr_col);  // Down
    fill(tab, size, original_char, curr_row, curr_col - 1);  // Left
    fill(tab, size, original_char, curr_row, curr_col + 1);  // Right
}

// Entry point function, initiates flood fill operation
// Takes grid (table), its dimensions & starting point
void	flood_fill(char **tab, t_point size, t_point begin)
{
	// Get char at starting position: this is the char to replace in connected region
	char	original_char = tab[begin.y][begin.x];

	// Start flood fill from beginning position using helper to recursively fill connected region
	fill (tab, size, original_char, begin.y, begin.x);
}
