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

# define ERR_MALLOC			"Malloc error: allocation is failed"
# define ERR_MAP_NUM		"MAP error: included number is inappropriate"
# define ERR_MAP_COLOR		"MAP error: included color code is inappropriate"

# define WHITE 0xffffff
# define RED 0xe80c0c

typedef struct s_coord
{
	int				z;
	int				color;
	struct s_coord	*next;
}				t_coord;

typedef struct s_point
{
	float			x;
	float			y;
}				t_point;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				**z_matrix;  //I'll delete
	t_coord			**coords;
	int				zoom;
	int				color;
	void			*mlx_ptr;
	void			*win_ptr;
}				t_fdf;

typedef struct s_terminal
{
	int				x;
	int				y;
}				t_terminal;

// ---------------------------read_file.c
void		read_file(char *file_name, t_fdf *data);
int			get_height(char *file_name);
int			ft_wdcounter(char c, char *str);

// ---------------------------read_file_utils.c
int			convert_char(char c);
long long	ft_atoi_hex(const char *str);
t_coord		*deal_args(char *str);
void		get_args(char *str, t_coord *coord);
int			get_color(char *str);

// ---------------------------read_file_utils2.c
int			check_num(char *str);
int			check_hex(char *str);
int			check_color_exist(char *str);
void		check_args(char *str);

// ---------------------------read_file_utils3.c
char		*ft_strdup_till(const char *s1, char c);
void		init_lst(t_coord *lst);
void		ft_lstadd_back(t_coord **lst, t_coord *new);

// ---------------------------free.c
void		two_dim_free(int **buf);

// ---------------------------draw.c
void		bresenham(t_point p, float x1, float y1, t_fdf *data);
void		draw(t_fdf *data);

// ---------------------------draw_utils.c
int			get_max(int a, int b);
void		set_color(t_fdf *data, int z);
float		mod(float i);
void		zoom(t_point *p, float *x1, float *y1, t_fdf *data);

// ---------------------------replace.c
void		isometric2(float *x, float *y);
void		replace_point(float *x, float *y, t_fdf *data);
t_terminal	bresen_2nd(t_point p, float x1, float y1, t_fdf *data);
t_terminal	get_terminal(t_fdf *data);

// ---------------------------error_deal.c
void		malloc_error(void *buf);
void		map_arg_error(char *message);

#endif
