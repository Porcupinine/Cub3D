/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 14:06:19 by laura         #+#    #+#                 */
/*   Updated: 2024/01/26 11:48:16 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
