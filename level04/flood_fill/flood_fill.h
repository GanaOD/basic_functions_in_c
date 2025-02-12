#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

// a pair of 2D coordinates that can represent both:
// 		position (x,y coordinates)
//		& size/dimensions (width, height)
typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif