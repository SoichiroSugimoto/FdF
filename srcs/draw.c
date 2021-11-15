/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:38:46 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/15 15:12:07 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = y * data->line_length + x * data->bits_per_pixel / 8;
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
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

t_step	get_step(t_point p, float x1, float y1)
{
	t_step	step;
	int		max;

	step.x_step = 0;
	step.y_step = 0;
	step.x_step = x1 - p.x;
	step.y_step = y1 - p.y;
	max = get_max(mod(step.x_step), mod(step.y_step));
	step.x_step /= max;
	step.y_step /= max;
	return (step);
}

void	bresenham(t_point p, float x1, float y1, t_fdf *data)
{
	t_step	step;
	int		z;
	int		z1;

	z = data -> zoom * data->altitude * get_z_value((int)p.y, (int)p.x, data);
	z1 = data -> zoom * data->altitude * get_z_value((int)y1, (int)x1, data);
	zoom(&p, &x1, &y1, data);
	isometric(&p.x, &p.y, z);
	isometric(&x1, &y1, z1);
	replace_point(&p.x, &p.y, data);
	replace_point(&x1, &y1, data);
	step = get_step(p, x1, y1);
	while ((int)(p.x - x1) || (int)(p.y - y1))
	{
		my_mlx_pixel_put(data, p.x, p.y, data->color);
		p.x += step.x_step;
		p.y += step.y_step;
	}
	if (!((int)(p.x - x1) || (int)(p.y - y1)))
		my_mlx_pixel_put(data, p.x, p.y, data->color);
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
