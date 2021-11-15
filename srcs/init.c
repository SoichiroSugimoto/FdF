/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:35:53 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/15 12:35:55 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_fdf *data)
{
	data->width = 30;
	data->height = 20;
	data->altitude = 1;
	data->zoom = 20;
	data->z_max = 0;
}
