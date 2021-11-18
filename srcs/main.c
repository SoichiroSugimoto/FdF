/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:39:41 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/18 17:32:35 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test_draw(t_fdf *data, char *str);

int	deal_key(int key, t_fdf *data)
{
	if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc <= 1)
		error_message(ERR_NO_ARG);
	if (filename_check(argv[1]) == FAULT)
		error_message(ERR_FILE_NAME);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	malloc_error(data);
	init_struct(data);
	read_file(argv[1], data);
	data->file_name = argv[1];
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, argv[1]);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}
