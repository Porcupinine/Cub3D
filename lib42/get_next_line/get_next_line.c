/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:01 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/01/25 15:35:52 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

/***
 * Start the line in case line is empty
 * @param buff What was last read from fd
 * @param lines Where the function stores the line
 * @param buff_len Size of the buff
 * @param len Which interation we are inside the buff
 * @return 0 if it fails, 3 if it doesn't find a new line or null
 * terminator and 2 if it finds the new line or null terminator
 */
static int	start_line(char *buff, char **lines, long buff_len, long *len)
{
	long		start;
	long		line_size;

	start = *len;
	while (*len < (buff_len) && buff[*len] != '\n' && buff[*len] != '\0')
		(*len)++;
	line_size = *len - start;
	if (*len == buff_len)
		(*lines) = ft_strlcpy_gnl(buff + start, line_size);
	else if (buff[*len] == '\n' || buff[*len] == '\0')
	{
		if (buff[*len] == '\n')
			line_size++;
		(*lines) = ft_strlcpy_gnl(buff + start, line_size);
		(*len)++;
		return (2);
	}
	return (3);
}

/***
 * Finish the line in case line is not empty
 * @param buff What was last read from fd
 * @param lines Where the function stores the line
 * @param buff_len Size of the buff
 * @param len Which interation we are inside the buff
 * @return 0 if it fails, 3 if it doesn't find a new line or null
 * terminator and 2 if it finds the new line or null terminator
 */
static int	finish_line(char *buff, char **lines, long buff_len, long *len)
{
	long	start;
	char	*temp;
	long	line_size;

	start = *len;
	while (*len < (buff_len) && buff[*len] != '\n' && buff[*len] != '\0')
		(*len)++;
	line_size = *len - start;
	temp = *lines;
	if (*len == buff_len)
	{
		(*lines) = ft_strjoin_gnl((*lines), &(buff[start]), line_size);
		free(temp);
	}
	else if (buff[*len] == '\n' || buff[*len] == '\0')
	{
		if (buff[*len] == '\n')
			line_size++;
		(*lines) = ft_strjoin_gnl((*lines), &(buff[start]), line_size);
		(*len)++;
		free(temp);
		return (2);
	}
	return (3);
}

/***
 * call get lines because 25 lines is a shity limit
 * @param buff buffer to copy from
 * @param lines where to put what was read
 * @param buff_len size of the buffer
 * @param len where are we
 * @return lines
 */
static long	get_the_line(char *buff, char **lines, long buff_len, long *len)
{
	long	ret;

	if (*lines == NULL)
		ret = start_line(buff, lines, buff_len, len);
	else
		ret = finish_line(buff, lines, buff_len, len);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*lines;
	static long		len = 0;
	static long		buff_len = 0;
	long			ret;

	lines = NULL;
	while (1)
	{
		if (len >= buff_len)
		{
			buff_len = read(fd, buff, BUFFER_SIZE);
			if (buff_len == 0)
				return (lines);
			if (buff_len < 0)
				return (free(lines), NULL);
			len = 0;
		}
		if (buff_len > 0)
			ret = get_the_line(buff, &lines, buff_len, &len);
		if (ret == 2)
			break ;
	}
	return (lines);
}
