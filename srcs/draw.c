#include "../includes/fdf.h"

int	get_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	get_color(int z, int z1)
{
	if (z || z1)
		return (0xe80c0c);
	return (0xffffff);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	isometric(float *x, float *y, float z)
{
	printf("(x, y, z) = (%f, %f, %f)\n", *x, *y, z);
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	// -----------zoom-----------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// -----------color-----------
	data->color = (z) ? 0xe80c0c : 0xffffff;
	// -----------3D-----------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x_step = x1 - x;
	y_step = y1 - y;
	max = get_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	printf("x(%f %f) y(%f %f)\n", x, x1, y, y1);
	printf("x_step %f\n", x_step);
	printf("y_step %f\n", y_step);
	printf("%d    %d\n", (int)(x - x1), (int)(y - y1));
	while ((int)(x - x1)|| (int)(y - y1))
	{
		printf("x(%d %d) y(%d %d)\n", (int)x, (int)x1, (int)y, (int)y1);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
