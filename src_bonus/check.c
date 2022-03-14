/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:18:27 by woberon           #+#    #+#             */
/*   Updated: 2022/03/14 20:29:12 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_size_map2_bonus(char *line, int j, int fd, t_game **game)
{
	int	length;

	while (line)
	{
		if (line != NULL)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				length = ft_strlen(line) - 1;
			else
				length = ft_strlen(line);
			if ((*game)->win_draw.x != length)
			{
				write(1, "check line length!\n", 19);
				exit(0);
			}
			line = get_next_line(fd);
			free(line);
		}
		j++;
	}
	(*game)->win_draw.y = j;
}

void	check_chr_bonus(char *path)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = fd_open_bonus(path);
	while (fd > 0)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] \
			!= 'E' && line[i] != 'C' && line[i] != 'A')
			{
				write(1, "Check character \n", 17);
				exit (0);
			}
			i++;
		}
		free(line);
	}
}

void	check_size_map_bonus(char *path, t_game **game)
{
	int		fd;
	char	*line;
	int		j;

	*game = malloc(sizeof(t_game));
	line = NULL;
	fd = fd_open_bonus(path);
	j = 0;
	line = get_next_line(fd);
	if (!ft_strlen(line))
	{
		write(2, "Not valid map\n", 14);
		exit(0);
	}
	(*game)->win_draw.x = ft_strlen(line) - 1;
	check_size_map2_bonus(line, j, fd, game);
	free(line);
}

void	read_map_bonus(char *path, t_game **game)
{
	int	fd;
	int	i;

	(*game)->score = 0;
	i = 0;
	(*game)->file_map = NULL;
	(*game)->file_map = malloc(sizeof(t_game) * (*game)->win_draw.y);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(0);
	(*game)->file_map[i] = get_next_line(fd);
	while ((*game)->file_map[i])
	{
		i++;
		(*game)->file_map[i] = get_next_line(fd);
	}
	(*game)->chr.player = 0;
	(*game)->chr.exit = 0;
	search_chr_bonus(game);
}
