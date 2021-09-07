#include "../includes/fdf.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] != ',')
	{
		if (str[i] && !('0' <= str[i] && str[i] <= '9'))
			return (FAULT);
		i++;
	}
	return (TRUE);
}

int	check_color_exist(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ',')
			return (i);
		i++;
	}
	return (FAULT);
}

int	check_hex(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = check_color_exist(str) + 1;
	if (!(str[i] == '0' && str[i + 1] == 'x'))
		return (FAULT);
	i += 2;
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') ||
				('A' <= str[i] && str[i] <= 'F') ||
				('a' <= str[i] && str[i] <= 'f')))
			map_arg_error(ERR_MAP_COLOR);
		n++;
		if (n > 6)
			map_arg_error(ERR_MAP_COLOR);
		i++;
	}
	return (TRUE);
}

void	check_args(char *str)
{
	if (check_num(str) == FAULT)
		map_arg_error(ERR_MAP_NUM);
	if (check_color_exist(str) != FAULT && check_hex(str) == FAULT)
		map_arg_error(ERR_MAP_COLOR);
}
