/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:58:51 by akrepkov          #+#    #+#             */
/*   Updated: 2023/06/02 20:30:48 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef WIDTH
#  define WIDTH 2000
# endif
# ifndef HEIGHT
#  define HEIGHT 2000
# endif
# ifndef BLACK
#  define BLACK 0xFF0000FF
# endif

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**matrix;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
	int			z_max;
	int			z_min;
	float		dx;
	float		dy;
	float		zoom;
	float		p_x;
	float		p_y;
	float		zoom_x;
	float		zoom_y;
	float		a;
	float		b;
	float		zoom_z;
	int			y2h;
	int			x2h;
	float		sx;
	float		sy;
	int			y2v;
	int			x2v;
	int			z_1;
	int			z2;
	float		e2;
	int			z3;
	int			dif;
}	t_fdf;

void	set_param(t_fdf *data);
int		read_map(char *file, t_fdf *data);
void	drawing_line(t_fdf *data, int color);
char	*newstring(int size);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, char c);
void	my_scroll(double xdelta, double ydelta);
void	my_hook(mlx_key_data_t keydata, t_fdf *data);
int		fm(int a);
void	my_rothook(mlx_key_data_t keydata, t_fdf *data);
void	bresenhamster_1(t_fdf *data, int x1, int y1, int color);
void	calculations(t_fdf *data, int *x1, int *y1, float *err);
void	ft_perror(char *str);
void	freedom(t_fdf *data);
void	check_the_z(t_fdf *data, int res);

#endif
