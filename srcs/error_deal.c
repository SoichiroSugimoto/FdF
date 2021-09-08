#include "../includes/fdf.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, 1);
	exit(0);
}

void	malloc_error(void *buf)
{
	if (buf == NULL)
	{
		ft_putstr_fd(ERR_MALLOC, 1);
		exit(0);
	}
}

void	wd_cnt_checker(int	width, int wd_cnt)
{
	if (width < wd_cnt)
	{
		ft_putstr_fd(ERR_LARGER_WID, 1);
		exit(0);
	}
	if (width > wd_cnt)
	{
		ft_putstr_fd(ERR_SMALLER_WID, 1);
		exit(0);
	}
}
