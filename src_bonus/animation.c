/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:13:28 by woberon           #+#    #+#             */
/*   Updated: 2022/03/14 17:13:30 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_potion_bonus(t_game **game)
{
	static int	time;

	(*game)->chr.collect += 1;
	if (time == 0)
	{
		draw_bonus("./texture/potion1.xpm", game);
	}
	else if (time == 1)
		draw_bonus("./texture/potion2.xpm", game);
	else if (time == 2)
		draw_bonus("./texture/potion3.xpm", game);
	time++;
	if (time == 3)
		time = 0;
}

void	draw_alien_bonus(t_game **game)
{
	static int	time;

	if (time == 0)
		draw_bonus("./texture/attack4.xpm", game);
	else if (time == 1)
		draw_bonus("./texture/attack3.xpm", game);
	else if (time == 2)
		draw_bonus("./texture/attack2.xpm", game);
	else if (time == 3)
		draw_bonus("./texture/attack1.xpm", game);
	time++;
	if (time == 4)
		time = 0;
}

void	draw_player_bonus(t_game **game, int i, int j)
{
	static int	time;

	(*game)->pos_player.x = j;
	(*game)->pos_player.y = i;
	if (time == 0)
		draw_bonus("./texture/player1.xpm", game);
	else if (time == 1)
		draw_bonus("./texture/player2.xpm", game);
	else if (time == 2)
		draw_bonus("./texture/player3.xpm", game);
	else if (time == 3)
		draw_bonus("./texture/player4.xpm", game);
	time++;
	if (time == 4)
		time = 0;
}
