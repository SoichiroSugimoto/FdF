#include "../includes/fdf.h"

void	malloc_error(void *buf)
{
	if (buf == NULL)
	{
		ft_putstr_fd(ERR_MALLOC, 0);
		exit(0);
	}
}

void	map_arg_error(char *message)
{
	ft_putstr_fd(message, 0);
	exit(0);
}
