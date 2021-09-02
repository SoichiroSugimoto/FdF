#include "../includes/fdf.h"

void	isometric2(float *x, float *y)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8);
}

void	bresen_2nd(float x, float y, float x1, float y1, t_terminal *point, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	zoom(&x, &y, &x1, &y1, data);
	isometric2(&x, &y);
	isometric2(&x1, &y1);
	x_step = x1 - x;
	y_step = y1 - y;
	max = get_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		x += x_step;
		y += y_step;
	}
	point->x = (int)x1;
	point->y = (int)y1;
}

t_terminal	get_terminal(t_fdf *data)
{
	int			x;
	int			y;
	t_terminal	point;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresen_2nd(x, y, x + 1, y, &point, data);
			if (y < data->height - 1)
				bresen_2nd(x, y, x, y + 1, &point, data);
			x++;
		}
		y++;
	}
	return (point);
}

void	replace_point(float *x, float *y, t_fdf *data)
{
	t_terminal	point;

	point = get_terminal(data);
	*x += WIDTH / 2 - point.x / 2;
	*y += (HEIGHT - point.y) / 2;
}
