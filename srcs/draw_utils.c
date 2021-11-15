/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:38:34 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/15 13:53:54 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
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
