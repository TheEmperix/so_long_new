/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:23:06 by woberon           #+#    #+#             */
/*   Updated: 2022/06/24 13:02:28 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define W 13
# define S 1
# define A 0
# define D 2

# include "../minilibx/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_size {
	int	x;
	int	y;
}	t_size;

typedef struct s_chr {
	int	player;
	int	exit;
	int	collect;
}	t_chr;

typedef struct s_game {
	char		**file_map;
	void		*mlx;
	void		*win;
	t_chr		chr;
	t_size		pos_player;
	t_size		win_draw;
	int			score;
}	t_game;

void	check_chr_bonus(char *path);
void	check_size_map_bonus(char *path, t_game **game);
void	check_size_map2_bonus(char *line, int j, int fd, t_game **game);
void	read_map_bonus(char *path, t_game **game);
void	counter_bonus(char **file_map, t_game *game);
void	map2_bonus(char **file_map, t_game *game);
void	search_chr_bonus(t_game **game);
void	check_pec_bonus(t_game **game);
void	valid_waterh_bonus(t_game **game);
void	valid_waterv_bonus(t_game **game);
void	ft_putnbr_bonus(int n);
void	ft_putstr_bonus(char *str);
void	ft_extension_bonus(char *path);
void	draw_potion_bonus(t_game **game);
void	draw_bonus(char *path, t_game *game);
void	draw_alien_bonus(t_game **game);
void	draw_player_bonus(t_game **game, int i, int j);
void	move_bonus(int keycode, t_game **game);
void	draw_map_bonus(char map, t_game *game, int i, int j);
void	finish_game_bonus(t_game **game);
void	game_bonus(t_game **game);
int		ft_close_bonus(int key);
int		fd_open_bonus(char *path);
int		ft_value_bonus(int n);
int		ft_len_bonus(int n);
int		player_moves_bonus(int keycode, t_game **game);
int		main(int argc, char **argv);
char	*ft_itoa_bonus(int n);

#endif
