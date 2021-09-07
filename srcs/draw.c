#include "../includes/fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	set_color(t_fdf *data, int z, int color_code)
{
	if (color_code == 0 && !z)
		data->color = C_YELLOW;
	else if (color_code == 0 && z)
		data->color = RED;
	else
		data->color = color_code;
}

int	get_z_value(int	x, int y, t_fdf *data)
{
	t_coord	*lst;
	int		i;

	i = 0;
	lst = data->coords[x];
	while (i < y)
	{
		lst = lst->next;
		i++;
	}
	set_color(data, lst->z, lst->color);
	return (lst->z);
}

void	bresenham(t_point p, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = get_z_value((int)p.y, (int)p.x, data);
	z1 = get_z_value((int)y1, (int)x1, data);
	zoom(&p, &x1, &y1, data);
	// set_color(data, z);
	isometric(&p.x, &p.y, z);
	isometric(&x1, &y1, z1);
	replace_point(&p.x, &p.y, data);
	replace_point(&x1, &y1, data);
	x_step = x1 - p.x;
	y_step = y1 - p.y;
	max = get_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p.x - x1) || (int)(p.y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p.x, p.y, data->color);
		p.x += x_step;
		p.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_point	p;

	p.y = 0;
	while (p.y < data->height)
	{
		p.x = 0;
		while (p.x < data->width)
		{
			if (p.x < data->width - 1)
				bresenham(p, p.x + 1, p.y, data);
			if (p.y < data->height - 1)
				bresenham(p, p.x, p.y + 1, data);
			p.x++;
		}
		p.y++;
	}
}
