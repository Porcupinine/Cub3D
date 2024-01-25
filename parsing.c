
#include "cub3d.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		j;

	j = 0;
	len = strlen(s); //change
	ptr = (void *)malloc(sizeof(*s) * (len + 1));
	if (ptr == 0)
		return (0);
	while (j <= len)
	{
		ptr[j] = s[j];
		j++;
	}
	return (ptr);
}

int	*map_to_int(t_cub *data, char *str)
{
	int		i;
	int		*res;
	int j = 0;

	i = 0;
	res = malloc(sizeof(int) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i] - '0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	read_map(char *file, t_cub *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	data->height = get_height(file);
	// printf("Height %d\n", data->height);
	data->matrix = malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix)
		return (-1); //perror
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ; //also free things
		data->width = ft_strlen(line); //change
		data->matrix[i] = map_to_int(data, line);
		i++;
		free(line);
	}
	data->matrix[i] = NULL; // + check if the characters are right
	close(fd);
	// data->width_map = WIDTH / 4;
	// data->height_map = HEIGHT / 4;
	// data->scale_map = (data->width_map / data->width < data->height_map / data->height) ? data->width_map / data->width : data->height_map / data->height;
	return (0);
}