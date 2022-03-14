/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:04 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:19:05 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int keycode, t_game *game)
{
	if (keycode == W)
		game->pos_player.y -= 1;
	if (keycode == S)
		game->pos_player.y += 1;
	if (keycode == A)
		game->pos_player.x -= 1;
	if (keycode == D)
		game->pos_player.x += 1;
	write(1, "moves: ", 8);
	ft_putnbr(game->score);
	write(1, "\n", 1);
}

void	finish_game(t_game *game)
{
	if (game->file_map[game->pos_player.y][game->pos_player.x] == 'e')
	{
		ft_putstr("you won !\n");
		exit(0);
	}
	if (game->file_map[game->pos_player.y][game->pos_player.x] == 'A')
	{
		ft_putstr("game is over!\n");
		exit(0);
	}
}

void	redraw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file_map[i])
	{
		j = 0;
		while (game->file_map[i][j])
		{
			if (game->file_map[i][j] == 'P')
			{
				game->file_map[i][j] = '0';
			}
			if (i == game->pos_player.y && j == game->pos_player.x)
				game->file_map[i][j] = 'P';
			if (game->chr.collect == 0 && game->file_map[i][j] == 'E')
				game->file_map[i][j] = 'e';
			finish_game(game);
			j++;
		}
		i++;
	}
}

int	player_moves(int keycode, t_game **game)
{
	if (keycode == 53)
		exit(0);
	move(keycode, *game);
	if ((*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] !=
		'1' &&
		(*game)->file_map[(*game)->pos_player.y][(*game)->pos_player.x] != 'E')
	{
		redraw(*game);
		(*game)->score += 1;
	}
	map((*game)->file_map, *game);
	return (0);
}
