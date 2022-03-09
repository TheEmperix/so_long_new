#include "so_long_bonus.h"

void	draw_potion(t_game *vars)
{
	static int	time;

	vars->chr.collect += 1;
	if (time % 9 < 3)
	{
		draw("./xpm/potion1.xpm", vars);
	}
	else if (time % 9 < 6)
		draw("./xpm/potion2.xpm", vars);
	else
		draw("./xpm/potion3.xpm", vars);
	time++;
	if (time == 10)
		time = 0;
}

void	draw_alien(t_game *vars)
{
	static int	time;

	if (time == 0)
		draw("./xpm/alien1.xpm", vars);
	else if (time == 1)
		draw("./xpm/alien2.xpm", vars);
//	else if (time == 0
//		draw("./xpm/alien3.xpm", vars);
//	else if (time == 1 && keycode == A)
//		draw("./xpm/alien4.xpm", vars);
	time++;
	if (time == 3)
		time = 0;
}

void	draw_player(t_game *vars, int i, int j)
{
	static int	time;
	int			keycode = 23;

	vars->pos_player.x = j;
	vars->pos_player.y = i;
	if (time == 0)
	{
		if (keycode == 23)
			draw("./xpm/player5.xpm", vars);
		draw("./xpm/player1.xpm", vars);
	}
	else if (time == 1)
		draw("./xpm/player2.xpm", vars);
	else if (time == 2)
		draw("./xpm/player3.xpm", vars);
	else if (time == 3)
		draw("./xpm/player4.xpm", vars);
	time++;
	if (time == 4)
		time = 0;
}
