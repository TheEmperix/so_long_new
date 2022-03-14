/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:11 by woberon           #+#    #+#             */
/*   Updated: 2022/03/13 20:52:55 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	search_chr_bonus(t_game **game)
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
				(*game)->chr.player += 1;
			if ((*game)->file_map[i][j] == 'E')
				(*game)->chr.exit += 1;
			if ((*game)->file_map[i][j] == 'C')
				(*game)->chr.collect += 1;
			j++;
		}
		i++;
	}
	check_pec_bonus(game);
}

void	check_pec_bonus(t_game **game)
{
	if ((*game)->chr.exit <= 0 || (*game)->chr.collect <= 0)
	{
		write(1, "\nCheck you chr\n", 15);
		exit(0);
	}
	if ((*game)->chr.player != 1)
	{
		write(1, "\nCheck you start position\n", 27);
		exit(0);
	}
	write(1, "\n", 1);
	valid_waterh_bonus(game);
}

void	valid_waterh_bonus(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game)->file_map[i])
	{
		j = 0;
		while ((*game)->file_map[i][j] != '\n' && \
		(*game)->file_map[i][j] != 0)
		{
			if ((*game)->file_map[0][j] != '1' || \
			(*game)->file_map[(*game)->win_draw.y - 1][j] != '1')
			{
				ft_putstr_bonus("Wall is not valid\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	valid_waterv_bonus(game);
}

void	valid_waterv_bonus(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game)->file_map[i])
	{
		j = 0;
		while ((*game)->file_map[i][j])
		{
			if ((*game)->file_map[i][(*game)->win_draw.x - 1] != '1')
			{
				ft_putstr_bonus("Wall is not valid\n");
				exit(0);
			}
			if ((*game)->file_map[i][0] != '1')
			{
				ft_putstr_bonus("Wall is not valid\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
