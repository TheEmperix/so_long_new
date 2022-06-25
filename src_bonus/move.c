/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:04 by woberon           #+#    #+#             */
/*   Updated: 2022/06/24 13:34:33 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_bonus(int keycode, t_game **game)
{
	if (keycode == 13 || keycode == 126)
		(*game)->pos_player.y -= 1;
	if (keycode == 1 || keycode == 125)
		(*game)->pos_player.y += 1;
	if (keycode == 0 || keycode == 123)
		(*game)->pos_player.x -= 1;
	if (keycode == 2 || keycode == 124)
		(*game)->pos_player.x += 1;
	write(1, "Moves: ", 8);
	ft_putnbr_bonus((*game)->score);
	write(1, "\n", 1);
}

void	finish_game_bonus(t_game **game)
{
	if ((*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] == 'e')
	{
		ft_putstr_bonus("You win !\n");
		exit(0);
	}
	if ((*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] == 'A')
	{
		ft_putstr_bonus("Game Over!\n");
		exit(0);
	}
}

void	game_bonus(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game)->file_map[i])
	{
		j = 0;
		while ((*game)->file_map[i][j])
		{
			if ((*game)->file_map[i][j] == 'P')
			{
				(*game)->file_map[i][j] = '0';
			}
			if (i == (*game)->pos_player.y && j == (*game)->pos_player.x)
				(*game)->file_map[i][j] = 'P';
			if ((*game)->chr.collect == 0 && (*game)->file_map[i][j] == 'E')
				(*game)->file_map[i][j] = 'e';
			finish_game_bonus(game);
			j++;
		}
		i++;
	}
}

int	player_moves_bonus(int keycode, t_game **game)
{
	if (keycode == 53)
		exit(0);
	move_bonus(keycode, game);
	if ((*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] !=
		'1' &&
		(*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] !=
		'E')
	{
		game_bonus(game);
		(*game)->score += 1;
	}
	counter_bonus((*game)->file_map, *game);
	return (0);
}
