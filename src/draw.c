/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:18:45 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:20:19 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(char *path, t_game *vars)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image(vars->mlx, path, &x, &y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		chr, vars->win_draw.x, vars->win_draw.y);
}

void	draw_map(char map, t_game *vars, int i, int j)
{
	if (map == '1')
		draw("./texture/water.texture", vars);
	else if (map == '0')
		draw("./texture/ground.texture", vars);
	else if (map == 'C')
	{
		draw("./texture/potion.texture", vars);
		vars->chr.collect += 1;
	}
	else if (map == 'E')
	{
		draw("./texture/door_close.texture", vars);
	}
	else if (map == 'e')
		draw("./texture/door_open.texture", vars);
	else if (map == 'P')
	{
		vars->pos_player.x = j;
		vars->pos_player.y = i;
		draw("./texture/player.texture", vars);
	}
	else if (map == 'A')
		draw("./texture/alien.texture", vars);
}

void	map(char	**file_map, t_game	*vars)
{
	int		i;
	int		j;

	i = 0;
	vars->win_draw.y = 0;
	vars->chr.collect = 0;
	while (file_map[i])
	{
		vars->win_draw.x = 0;
		j = 0;
		while (file_map[i][j])
		{
			draw_map(file_map[i][j], vars, i, j);
			j++;
			vars->win_draw.x += 50;
		}
		vars->win_draw.y += 50;
		i++;
	}
}
