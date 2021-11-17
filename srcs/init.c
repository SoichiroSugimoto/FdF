/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:35:53 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/17 12:09:33 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_fdf *data)
{
	data->all_sides = (t_sides *)malloc(sizeof(t_sides));
	malloc_error(data->all_sides);
	data->width = 30;
	data->height = 20;
	data->altitude = 1;
	data->zoom = 20;
	data->z_max = 0;
	data->all_sides->x_min = 0;
	data->all_sides->y_min = 0;
	data->all_sides->x_max = 0;
	data->all_sides->y_max = 0;
}
