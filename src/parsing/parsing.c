#include "../../includes/parsing.h"
#include "../../Lib42/includes/libft.h"
#include "../../Lib42/includes/gnl.h"
#include <fcntl.h>


int get_textures(int fd, t_parse_data *cub_data) {
	char *line;
	line = get_next_line(fd);
	if (line )


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

int get_data(char *file) {
	int fd;
	t_parse_data cub_data;
	fd = 0;
	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1) {
		ft_error("Fail to read file\n");
	}
	get_textures(fd, cub_data);
}