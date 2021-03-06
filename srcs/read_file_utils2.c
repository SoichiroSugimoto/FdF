/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:40:32 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/29 14:58:18 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	filename_check(char *filename)
{
	int	i;

	i = 1;
	if (filename[0] == '.')
		return (FAULT);
	while (filename[i] != '.')
		i++;
	i++;
	if (filename[i] == 'f' && filename[i + 1] == 'd' && filename[i + 2] == 'f')
		return (TRUE);
	return (FAULT);
}

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
		if (!(('0' <= str[i] && str[i] <= '9')
				|| ('A' <= str[i] && str[i] <= 'F')
				|| ('a' <= str[i] && str[i] <= 'f')))
			error_message(ERR_MAP_COLOR);
		n++;
		if (n > 6)
			error_message(ERR_MAP_COLOR);
		i++;
	}
	return (TRUE);
}

void	check_args(char *str)
{
	if (check_num(str) == FAULT)
		error_message(ERR_MAP_NUM);
	if (check_color_exist(str) != FAULT && check_hex(str) == FAULT)
		error_message(ERR_MAP_COLOR);
}
