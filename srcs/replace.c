#include "../includes/fdf.h"

void	isometric2(float *x, float *y)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8);
}

t_terminal	bresen_2nd(t_point p, float x1, float y1, t_fdf *data)
{
	float		x_step;
	float		y_step;
	t_terminal	point;
	int			max;

	zoom(&p, &x1, &y1, data);
	isometric2(&x1, &y1);
	point.x = (int)x1;
	point.y = (int)y1;
	return (point);
}

t_terminal	get_terminal(t_fdf *data)
{
	t_terminal	point;
	t_point		p;

	p.y = 0;
	while (p.y < data->height)
	{
		p.x = 0;
		while (p.x < data->width)
		{
			if (p.x < data->width - 1)
				point = bresen_2nd(p, p.x + 1, p.y, data);
			if (p.y < data->height - 1)
				point = bresen_2nd(p, p.x, p.y + 1, data);
			p.x++;
		}
		p.y++;
	}
	return (point);
}

void	replace_point(float *x, float *y, t_fdf *data)
{
	t_terminal	point;

	printf("(1)(3)\n");
	point = get_terminal(data);
	printf("terminal: (%d, %d)\n", point.x, point.y);
	*x += WIDTH / 2 - point.x / 2;
	*y += (HEIGHT - point.y) / 2;
}
