typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;
// NB: x is 1st member, y is 2nd
// ∴ when initializing a t_point: (t_point){x, y}


// NB: row-major order for 2d array access (memory layout)
void	initialise_tab(char **tab, t_point size, t_point begin)
{
	if (!tab)
		return ;

	// initial static global / system entry boundary conditions
	// ensure begin coordinates are within given tab dimensions
	if (begin.y < 0 || begin.y >= size.y ||
			begin.x < 0 || begin.x >= size.x)
		return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	initialise_tab(tab, size, begin);

	// functionally unnecessary, but introduced for my mental model mapping / cognitive alignment
	// I want nomenclature that matches my mental model of functionality ("intent revealing")
	// this initial position, begin, becomes a dynamic traversal point
	t_point	current_position = begin;

	// store char beginning location in variable
	//		const value will be used repeatedly
	char	to_replace = tab[begin.y][begin.x];

	tab[begin.y][begin.x] = 'F';

	// let the recursion begin baby
	//		DFS. Pattern that speaks to me: circular, clockwise
	// incl. continuous dynamic boundary error-checking during traversal
	//		to ensure each transformation preserves boundary invariants
	
	// north, 0°
	if (current_position.y - 1 >= 0 && tab[current_position.y - 1][current_position.x] == to_replace)
		flood_fill(tab, size, (t_point){current_position.x, current_position.y - 1}); 
	
	// east, 90°
	if (current_position.x + 1 < size.x && tab[current_position.y][current_position.x + 1] == to_replace)
		flood_fill(tab, size, (t_point){current_position.x + 1, current_position.y});

	// south, 180°
	if (current_position.y + 1 < size.y && tab[current_position.y + 1][current_position.x] == to_replace)
		flood_fill(tab, size, (t_point){current_position.x, current_position.y + 1});

	// west, 270°
	if (current_position.x - 1 >= 0 && tab[current_position.y][current_position.x - 1] == to_replace)
		flood_fill(tab, size, (t_point){current_position.x - 1, current_position.y});
}