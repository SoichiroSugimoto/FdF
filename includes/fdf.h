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

# define WIDTH 700 * 3 / 2
# define HEIGHT 700

int	cnt;
typedef struct s_terminal
{
	int	x;
	int	y;
}					t_terminal;

typedef struct			s_point
{
	float					x;
	float					y;
}						t_point;
typedef struct	s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

void		read_file(char *file_name, t_fdf *data);
void		two_dim_free(int **buf);
void		bresenham(t_point p, float x1, float y1, t_fdf *data);
void		draw(t_fdf *data);
int			get_max(int a, int b);
void		set_color(t_fdf *data, int z);
float		mod(float i);
void		zoom(t_point *p, float *x1, float *y1, t_fdf *data);
void		isometric2(float *x, float *y);
void		replace_point(float *x, float *y, t_fdf *data);
t_terminal	bresen_2nd(t_point p, float x1, float y1, t_fdf *data);
t_terminal	get_terminal(t_fdf *data);

#endif
