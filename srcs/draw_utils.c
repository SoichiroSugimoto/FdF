#include "../includes/fdf.h"

int	get_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

void	set_color(t_fdf *data, int z)
{
	if (z)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	zoom(t_point *p, float *x1, float *y1, t_fdf *data)
{
	p->x *= data->zoom;
	p->y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}
