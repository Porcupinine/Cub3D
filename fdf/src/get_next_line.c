/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:35:16 by akrepkov          #+#    #+#             */
/*   Updated: 2023/03/30 10:02:58 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*check_bottle(char *reminder, int fd)
{
	char	*buf;
	int		done;

	buf = (char *)malloc(sizeof(*buf) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	done = 1;
	while (!ft_strchr_gnl(reminder, '\n') && done != '\0')
	{
		done = read(fd, buf, BUFFER_SIZE);
		if (done == -1)
		{
			free (reminder);
			free(buf);
			return (NULL);
		}
		buf[done] = '\0';
		reminder = ft_strjoin_gnl(reminder, buf);
	}
	free (buf);
	return (reminder);
}

char	*ft_get_line(char	*reminder)
{
	int		i;
	char	*line;
	int		j;

	j = 0;
	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (reminder[i] == '\n')
		i++;
	line = (char *)malloc((sizeof(*line) * i) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		line[j++] = reminder[i++];
	if (reminder[i] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*leftovers(char *reminder)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free (reminder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * (ft_strlen_gnl(reminder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i] != '\0')
		str[j++] = reminder[i++];
	str[j] = '\0';
	free (reminder);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	reminder = check_bottle(reminder, fd);
	if (!reminder)
		return (NULL);
	line = ft_get_line(reminder);
	reminder = leftovers(reminder);
	return (line);
}
