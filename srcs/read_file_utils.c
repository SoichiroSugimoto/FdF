#include "../includes/fdf.h"

int	convert_char(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	if (c == 'b' || c == 'B')
		return (11);
	if (c == 'c' || c == 'C')
		return (12);
	if (c == 'd' || c == 'D')
		return (13);
	if (c == 'e' || c == 'E')
		return (14);
	if (c == 'f' || c == 'F')
		return (15);
	if ('0' <= c && c <= '9')
		return (c - '0');
	return (0);
}

long long	ft_atoi_hex(const char *str)
{
	long long	res;
	int			i;
	int			sign;
	int			digit;

	res = 0;
	i = 0;
	sign = 1;
	digit = ft_strlen(str) - 1;
	while (digit >= 0)
	{
		res += (int)pow(16, i) * convert_char(str[digit]);
		i++;
		digit--;
	}
	return (res * sign);
}

void	get_args(char *str, t_coord *coord)
{
	char	*num;

	check_args(str);
	init_lst(coord);
	if (check_color_exist(str) != FAULT)
	{
		num = ft_strdup_till(str, ',');
		coord->z = ft_atoi(num);
		free(num);
		while (*str)
		{
			if (*str == ',')
				coord->color = get_color(str);
			str++;
		}
	}
	else
		coord->z = ft_atoi(str);
}

int	get_color(char *str)
{
	int	res;

	str += 2;
	res = ft_atoi_hex(str);
	return (res);
}

t_coord	*deal_args(char *str)
{
	char	**nums;
	int		i;
	int		width;
	t_coord	*coord;
	t_coord	*new;

	i = 0;
	coord = NULL;
	width = ft_wdcounter(' ', str);
	nums = ft_split(str, ' ');
	while (i != width)
	{
		new = (t_coord *)malloc(sizeof(t_coord));
		malloc_error(new);
		init_lst(new);
		get_args(nums[i], new);
		free(nums[i]);
		ft_lstadd_back(&coord, new);
		i++;
	}
	return (coord);
}
