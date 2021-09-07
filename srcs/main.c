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

void	print_all(t_coord *lst)
{
	int	n;

	n = 1;
	while (lst->next != NULL)
	{
		// printf("[%d]  ", n);
		printf("z : %d  /  ", lst->z);
		// printf("color : %x  /  ", lst->color);
		// printf("next : %p\n", lst->next);
		lst = lst->next;
		n++;
	}
	printf("[%d]  ", n);
	printf("z : %d  /  ", lst->z);
	printf("color : %x  /  ", lst->color);
	printf("next : %p\n", lst->next);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;
	int		j;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}
