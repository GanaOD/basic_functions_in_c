# variables: names and uses

## tab
likely short for table

more meaningful, explicit for meaningful for me: 
matrix_grid, character_grid...

ptr to ptrs: lets me represent & manipulate a 2D structure of chars



## s_point : dual-purpose struct

	for grid / table dimensions 
	starting position 
	tracking current position

an example of:

Code reuse - avoiding creating two very similar structures
Geometric abstraction - both cases really are just (x,y) coordinates in a 2D space


more meaningful name for me: s_vector2d

reflects that it's:
	A pair of 2D coordinates
	Can represent both position (x,y coordinates) & size/dimensions (width, height)
	More mathematically general/abstract