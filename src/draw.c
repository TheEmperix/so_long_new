/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:18:45 by woberon           #+#    #+#             */
/*   Updated: 2022/03/14 16:21:23 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(char *path, t_game *game)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	mlx_put_image_to_window(game->mlx, game->win,
		chr, game->win_draw.x, game->win_draw.y);
}

void	draw_map(char map, t_game *game, int i, int j)
{
	if (map == '1')
		draw("./texture/water.xpm", game);
	else if (map == '0')
		draw("./texture/ground.xpm", game);
	else if (map == 'C')
	{
		draw("./texture/potion.xpm", game);
		game->chr.collect += 1;
	}
	else if (map == 'E')
	{
		draw("./texture/door_close.xpm", game);
	}
	else if (map == 'e')
		draw("./texture/door_open.xpm", game);
	else if (map == 'P')
	{
		game->pos_player.x = j;
		game->pos_player.y = i;
		draw("./texture/player.xpm", game);
	}
	else if (map == 'A')
		draw("./texture/alien.xpm", game);
}

void	map(char	**file_map, t_game	*game)
{
	int		i;
	int		j;

	i = 0;
	game->win_draw.y = 0;
	game->chr.collect = 0;
	while (file_map[i])
	{
		game->win_draw.x = 0;
		j = 0;
		while (file_map[i][j])
		{
			draw_map(file_map[i][j], game, i, j);
			j++;
			game->win_draw.x += 50;
		}
		game->win_draw.y += 50;
		i++;
	}
}
