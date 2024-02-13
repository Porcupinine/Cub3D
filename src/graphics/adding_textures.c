#include "../../includes/utils.h"
#include "../../includes/checks.h"
#include "../../includes/parsing.h"
#include "../../includes/cub3d.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>

void	add_textures(t_data *data, int x, int line_height, int start, int end)
{
	uint8_t			*arr;
	double			factor;

	arr = data->walls->w->pixels;
	factor = (double)data->walls->w->height / line_height;
	double y_o  = (start - HEIGHT / 2 + line_height / 2) * factor;
	while (start < end)
	{
		int color = arr[((int)y_o * data->walls->w->width + x) * sizeof(int)];
		mlx_put_pixel(data->img, x, start, color);
		y_o += factor;
		start++;
	}
	printf ("Start texX %d\n", arr[(int)y_o * data->walls->w->width + (int)x]);
}