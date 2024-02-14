#include "../../includes/utils.h"
#include "../../includes/checks.h"
#include "../../includes/parsing.h"
#include "../../includes/cub3d.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>


int colorize(mlx_texture_t *texture, int x, int y, double dark)
{
	int	r;
	int	g;
	int	b;
	int rgba;

	r = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel];
	g = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel + 1];
	b = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel + 2];
	// if (dark == 0)
	// 	dark = 1;
	// if (dark > 10)
		rgba = get_rgba(r, g, b, 255);
	// else
		// rgba = get_rgba(r, g, b, (int)(200.00 * dark / 10));
	return (rgba);
}

void	add_textures(t_data *data, int x, int line_height, int start, int end, double dark)
{
	double			factor;

	factor = (double)data->walls->w->height / line_height;
	double y_o  = (start - HEIGHT / 2 + line_height / 2) * factor;
	while (start < end)
	{
		int color = colorize(data->walls->w, x, (int)y_o, dark);
		mlx_put_pixel(data->img, x, start, color);
		y_o += factor;
		start++;
	}
}
