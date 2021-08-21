#include "../includes/fdf.h"

int	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf	*data;
	int	i;
	int	j;

	i = 0;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	// -----------print------------
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%2d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 10;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}
