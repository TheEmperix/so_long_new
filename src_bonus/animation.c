#include "so_long_bonus.h"

void	draw_potion_bonus(t_game *game)
{
	static int	time;

	game->chr.collect += 1;
	if (time % 9 < 3)
	{
		draw_bonus("./texture/potion1.xpm", game);
	}
	else if (time % 9 < 6)
		draw_bonus("./texture/potion2.xpm", game);
	else
		draw_bonus("./texture/potion3.xpm", game);
	time++;
	if (time == 10)
		time = 0;
}

void	draw_alien_bonus(t_game *game)
{
	static int	time;

	if (time == 0)
		draw_bonus("./texture/alien1.xpm", game);
	else if (time == 1)
		draw_bonus("./texture/alien2.xpm", game);
	time++;
	if (time == 3)
		time = 0;
}

void	draw_player_bonus(t_game *game, int i, int j)
{
	static int	time;

	game->pos_player.x = j;
	game->pos_player.y = i;
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
