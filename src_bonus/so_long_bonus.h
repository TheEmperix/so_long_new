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

void	check_chr(char *path);
void	check_size_map(char *path, t_game **vars);
void	check_size_map2(char *line, int j, int fd, t_game *vars);
void	read_map(char *path, t_game *vars);
void	map(char **file_map, t_game *vars);
void	map2(char **file_map, t_game *vars);
int		player_moves(int keycode, t_game **vars);
void	search_chr(t_game *vars);
int		fd_open(char *path);
void	check_pec(t_game *vars);
void	valid_waterh(t_game *vars);
void	valid_waterv(t_game *vars);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
void	draw_potion(t_game *vars);
void	draw(char *path, t_game *vars);
void	draw_alien(t_game *vars);
void	draw_player(t_game *vars, int i, int j);
void	move(int keycode, t_game *vars);
//void	draw_score(t_game *vars);

#endif
