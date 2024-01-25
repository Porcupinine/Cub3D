
#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "./libs/MLX42/include/MLX42/MLX42.h"
# include "./libs/libft/libft.h"
# define BUFFER_SIZE 1
# define WIDTH 600
# define HEIGHT 600
# define PI 3.1415
# define RA 1.047
# define COLOR_AMMO 0xeda705
# define COLOR_BLUE 0xbfbd2c
# define COLOR_RED 0xFF0000FF


typedef struct s_cub
{
	int			width;
	int			height;
	int			width_map;
	int			height_map;
	int			scale_map;
	int			**matrix;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		plane_X;
	double		plane_Y;
	mlx_image_t	*img2;
	double angle;
	mlx_image_t		*img_player;

}	t_cub;

int		read_map(char *file, t_cub *data);
void	find_positions(t_cub *data);
void	find_direction(t_cub *data, int y, int x);


char	*newstring(int size);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, char c);
void	let_s_move(mlx_key_data_t keydata, t_cub *data);
void	player_movement(t_cub *data);
void	testing(t_cub *data);
void minimap_background(t_cub *data);
double fm(double a);
#endif