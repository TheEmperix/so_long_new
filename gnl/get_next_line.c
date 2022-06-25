/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:04:46 by woberon           #+#    #+#             */
/*   Updated: 2022/06/24 14:11:03 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_newline(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*gnl_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_reading(char *buffer, char *line, int fd)
{
	int	br;

	br = 1;
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	while (br)
	{
		br = read(fd, line, BUFFER_SIZE);
		if (br < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line[br] = '\0';
		buffer = ft_strjoin(buffer, line);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	buffer = gnl_reading(buffer, line, fd);
	if (!buffer)
		return (NULL);
	line = gnl_line(buffer);
	buffer = gnl_newline(buffer);
	return (line);
}