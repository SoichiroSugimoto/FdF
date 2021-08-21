#include "../includes/fdf.h"

int	ft_wdcounter(int c, char *str)
{
	int	n;

	n = 0;
	printf("[%s]\n", str);
	while (*str)
	{
		if (*str != c)
			n++;
		while (*str != c)
			str++;
		while (*str == c)
			str++;
	}
	return (n);
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
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

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	// width = ft_wdcounter(' ', line);
	width = 19;
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_line[i] = (int)ft_atoi(nums[i]);
		// printf("%d  -> %d\n", (int)ft_atoi(nums[i]), z_line[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
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
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	printf("here\n");
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
