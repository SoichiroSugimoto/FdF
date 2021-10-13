#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500 * 3 / 2
# define ZOOM 15
# define ALTITUDE 5

# define ERR_NO_ARG			"ARGS error: the argument is empty\n"
# define ERR_FILE_NAME		"FILE error: file name format is inappropriate\n"
# define ERR_FD				"FD error: fail to get file descriptor\n"
# define ERR_LARGER_WID		"Width error: the number of arguments is large\n"
# define ERR_SMALLER_WID	"Width error: the number of arguments is small\n"
# define ERR_MALLOC			"Malloc error: allocation is failed\n"
# define ERR_MAP_NUM		"MAP error: input number is inappropriate\n"
# define ERR_MAP_COLOR		"MAP error: innput color code is inappropriate\n"

# define WHITE 0xffffff
# define RED 0xe80c0c
# define C_YELLOW 0xffffe0

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
int			filename_check(char *filename);
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
void		set_color(t_fdf *data, int z, int color_code);
void		bresenham(t_point p, float x1, float y1, t_fdf *data);
void		draw(t_fdf *data);

// ---------------------------draw_utils.c
int			get_max(int a, int b);
float		mod(float i);
void		zoom(t_point *p, float *x1, float *y1, t_fdf *data);

// ---------------------------replace.c
void		isometric2(float *x, float *y);
void		replace_point(float *x, float *y, t_fdf *data);
t_terminal	bresen_2nd(t_point p, float x1, float y1, t_fdf *data);
t_terminal	get_terminal(t_fdf *data);

// ---------------------------error_deal.c
void		error_message(char *message);
void		malloc_error(void *buf);
void		wd_cnt_checker(int	width, int wd_cnt);

#endif
