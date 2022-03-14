/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:21:15 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:21:16 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

void	check_chr(char *path);
void	check_size_map(char *path, t_game **game);
void	check_size_map2(char *line, int j, int fd, t_game *game);
void	read_map(char *path, t_game *game);
void	map(char **file_map, t_game *game);
int		player_moves(int keycode, t_game **game);
void	search_chr(t_game *game);
int		fd_open(char *path);
void	check_pec(t_game *game);
void	valid_waterh(t_game *game);
void	valid_waterv(t_game *game);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	*ft_itoa(int n);

#endif
