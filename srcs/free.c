#include "../includes/fdf.h"

void	safe_free(char *buf)
{
	free(buf);
	buf = NULL;
}

void	two_dim_free(int **buf)
{
	while (*buf)
	{
		free(*buf);
		buf++;
	}
	free(buf);
}
