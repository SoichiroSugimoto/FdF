/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:34:16 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/17 12:36:53 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_image_center(t_fdf *data)
{
	data->all_sides->x_center
		= (data->all_sides->x_max + data->all_sides->x_min) / 2;
	data->all_sides->y_center
		= (data->all_sides->y_max + data->all_sides->y_min) / 2;
}

int	get_zoom(t_fdf *data)
{
	int	zoom;
	int	n;
	int	m;

	n = data->height * data->width;
	m = data->height;
	if (data->width >= data->height)
		m = data->width;
	zoom = 20;
	if (n >= 900 || data->z_max >= 15)
		zoom = 15;
	if (n >= 1000)
		zoom = 10;
	if (n >= 5000 || m >= 80 || data->z_max >= 50)
		zoom = 5;
	if (n >= 10000 || m >= 150)
		zoom = 3;
	if (n >= 40000 || data->z_max >= 60)
		zoom = 2;
	if (n >= 50000 || data->z_max >= 100)
		zoom = 1;
	return (zoom);
}
