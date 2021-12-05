/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:41:01 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/28 18:51:33 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric2(float *x, float *y)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8);
}

t_terminal	bresen_2nd(t_point p, float x1, float y1, t_fdf *data)
{
	t_terminal	point;

	zoom(&p, &x1, &y1, data);
	isometric2(&x1, &y1);
	point.x = (int)x1;
	point.y = (int)y1;
	return (point);
}

void	get_all_sides(t_fdf *data, t_terminal point)
{
	if (data->all_sides->x_min > (int)point.x)
		data->all_sides->x_min = (int)point.x;
	if (data->all_sides->y_min > (int)point.y)
		data->all_sides->y_min = (int)point.y;
	if (data->all_sides->x_max < (int)point.x)
		data->all_sides->x_max = (int)point.x;
	if (data->all_sides->y_max < (int)point.y)
		data->all_sides->y_max = (int)point.y;
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
			get_all_sides(data, point);
			p.x++;
		}
		p.y++;
	}
	return (point);
}

void	replace_point(float *x, float *y, t_fdf *data)
{
	*x += WIDTH / 2 - data->all_sides->x_center;
	*y += HEIGHT / 2 - data->all_sides->y_center;
}
