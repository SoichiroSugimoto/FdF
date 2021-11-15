/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:40:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/15 13:00:40 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_wdcounter(char c, char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str != c && *str)
			n++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (n);
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, 0, O_RDONLY);
	if (fd == -1)
		error_message(ERR_FD);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, 0, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wdcounter(' ', line);
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (i != width)
	{
		z_line[i] = (int)ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->coords = (t_coord **)malloc(sizeof(t_coord *) * (data->height + 1));
	malloc_error(data->coords);
	fd = open(file_name, 0, O_RDONLY);
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		wd_cnt_checker(data->width, ft_wdcounter(' ', line));
		data->coords[i] = deal_args(line, data);
		free(line);
		i++;
	}
	data->coords[i] = NULL;
	close(fd);
}
