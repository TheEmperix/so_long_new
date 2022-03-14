/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:18:45 by woberon           #+#    #+#             */
/*   Updated: 2022/03/13 20:52:55 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_bonus(char *path, t_game **game)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image((*game)->mlx, path, &x, &y);
	mlx_put_image_to_window((*game)->mlx, (*game)->win,
		chr, (*game)->win_draw.x, (*game)->win_draw.y);
}

void	draw_map_bonus(char map, t_game **game, int i, int j)
{
	if (map == '1')
		draw_bonus("./texture/water.xpm", game);
	else if (map == '0')
		draw_bonus("./texture/ground.xpm", game);
	else if (map == 'C')
	{
		draw_potion_bonus(game);
	}
	else if (map == 'E')
	{
		draw_bonus("./texture/door_close.xpm", game);
	}
	else if (map == 'e')
		draw_bonus("./texture/door_open.xpm", game);
	else if (map == 'P')
	{
		draw_player_bonus(game, i, j);
	}
	else if (map == 'A')
		draw_alien_bonus(game);
}

void	map2_bonus(char	**file_map, t_game	**game)
{
	int		i;
	int		j;

	i = 0;
	(*game)->win_draw.y = 0;
	(*game)->chr.collect = 0;
	while (file_map[i])
	{
		(*game)->win_draw.x = 0;
		j = 0;
		while (file_map[i][j])
		{
			draw_map_bonus(file_map[i][j], game, i, j);
			j++;
			(*game)->win_draw.x += 50;
		}
		(*game)->win_draw.y += 50;
		i++;
	}
}

void	counter_bonus(char **file_map, t_game **game)
{
	char	*str;
	char	*score;

	str = NULL;
	map2_bonus(file_map, game);
	score = ft_itoa_bonus((*game)->score);
	str = ft_strjoin("Moves: ", score);
	free(score);
	mlx_string_put((*game)->mlx, (*game)->win, 10, 10, 1, str);
	free(str);
}
