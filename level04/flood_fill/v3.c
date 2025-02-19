typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

void	flood_fill(char **tab, t_point size, t_point begin)
{
	/* 
	table given in tests

	flood_fill functionality:

	initial error checks:
	ensure tab valid:
		if (size->x > x) || (size->y) > y)
			error
	ensure begin coord is within table boundaries: not in 1st/last row/column
	(check in relation to size)
		if (begin->x < )
	

	determine char at begin coordinates
		assign to char variable? to_replace

	flood fill:
	from here: replace to_replace begin with F
	DFS algo:
		up, down, right, left
		recursive: stack will build up depth-wise & unwind
	logic:
		if same char as at begin, assign F
		else move on to other coords

	
	

	*/


}