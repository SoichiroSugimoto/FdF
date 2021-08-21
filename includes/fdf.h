#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct	fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif
