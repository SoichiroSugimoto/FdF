#include "../includes/fdf.h"

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
	// printf("get_width:  %s\n", line);
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
	printf("h: %d   w: %d\n", data->height, data->width);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, 0, O_RDONLY);
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		// printf("line: %s\n", line);//////////
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
