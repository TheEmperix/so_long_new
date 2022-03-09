/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:23 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:19:25 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key)
{
	(void)key;
	exit(0);
}

void	arg_read(char *map)
{
	while (*map)
		write(1, map++, 1);
	write(1, "\n", 1);
}

void	ft_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'r' && path[i - 2] == 'e' && path[i - 3] == 'b' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		write(1, "check you path! -> ", 19);
		arg_read(path);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		ft_extension(argv[1]);
		check_chr(argv[1]);
		check_size_map(argv[1], &game);
		read_map(argv[1], game);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->win_draw.x * 50, \
		game->win_draw.y * 50, "so_long");
		mlx_hook(game->win, 17, 0, ft_close, 0);
		map(game->file_map, game);
		mlx_key_hook(game->win, player_moves, &game);
		mlx_loop(game->mlx);
	}
	else
		write(1, "check your arguments!\n", 22);
	return (0);
}
