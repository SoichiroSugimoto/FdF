#include "../includes/fdf.h"

int	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int	get_zoom(t_fdf *data)
{
	int	i;

	return (i);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;
	int		j;

	i = 0;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->zoom = 10;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}
