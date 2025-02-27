typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

void	recursive_fill(char **tab, t_point size, t_point current, char target_char)
{
	// Base cases

	if (current.x < 0 || current.x >= size.x ||
			current.y < 0 || current.y >= size.y)
				return ; 	
	
	if (tab[current.y][current.x] != target_char)
		return ;

	// Fill current cell
	tab[current.y][current.x] = 'F';

	// Recursive exploration
	recursive_fill(tab, size, (t_point){current.x, current.y - 1}, target_char);
	recursive_fill(tab, size, (t_point){current.x, current.y + 1}, target_char);
  recursive_fill(tab, size, (t_point){current.x - 1, current.y}, target_char);
  recursive_fill(tab, size, (t_point){current.x + 1, current.y}, target_char);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target_char = tab[begin.y][begin.x];
	recursive_fill(tab, size, begin, target_char);
}