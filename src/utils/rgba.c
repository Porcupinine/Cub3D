/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 14:06:19 by laura         #+#    #+#                 */
/*   Updated: 2024/01/21 14:06:19 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Get the red channel.
int get_r(int rgba)
{
	// Move 3 bytes to the right and mask out the first byte.
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
	// Move 2 bytes to the right and mask out the first byte.
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
	// Move 1 byte to the right and mask out the first byte.
	return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
	// Move 0 bytes to the right and mask out the first byte.
	return (rgba & 0xFF);
}

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}