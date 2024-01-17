#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include <fcntl.h>

char *get_path (char* str)
{
	int count;
	int start;
	char *sub;

	count = 0;
	start = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '.' && str[count + 1] == '/')
		{
			start = count;
			while(ft_isalpha(str[count]) != 0)
				count++;
			sub = ft_substr(str, start, count - start);
		}
		if (str[count] != ' ')
			return (NULL);
		count++;
	}
	return(sub);
}

int search_textures(int fd, t_parse_data *cub_data)
{
	char *line;
	line = get_next_line(fd);
	if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
	{
		if(get_path(line) != NULL)
			cub_data->
		//check if valid path
	}
	if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
	{

		//check if valid path
	}
	if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
	{

		//check if valid path
	}
	if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
	{

		//check if valid path
	}
}

static void	check_extension(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == 0)
		ft_error("Error\nNo extension\n");
	if (ft_memcmp(ext, ".cub", 5))
		ft_error("Error\nWrong extension\n");
}

t_parse_data *get_data(char *file)
{
	int fd;
	void *cub_data;

	fd = 0;
	cub_data = ft_calloc(1, sizeof(t_parse_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Fail to read file\n");
	search_textures(fd, cub_data);
	return (cub_data);
}