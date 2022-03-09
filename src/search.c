/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:11 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:19:13 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_chr(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->file_map[i])
	{
		j = 0;
		while (vars->file_map[i][j])
		{
			if (vars->file_map[i][j] == 'P')
				vars->chr.player += 1;
			if (vars->file_map[i][j] == 'E')
				vars->chr.exit += 1;
			if (vars->file_map[i][j] == 'C')
				vars->chr.collect += 1;
			j++;
		}
		i++;
	}
	check_pec(vars);
}

void	check_pec(t_game *vars)
{
	if (vars->chr.exit <= 0 || vars->chr.collect <= 0)
	{
		write(1, "\ncheck you chr\n", 15);
		exit(0);
	}
	if (vars->chr.player != 1)
	{
		write(1, "\ncheck you start position\n", 27);
		exit(0);
	}
	write(1, "\n", 1);
	valid_waterh(vars);
}

void	valid_waterh(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->file_map[i])
	{
		j = 0;
		while (vars->file_map[i][j] != '\n' && \
		vars->file_map[i][j] != 0)
		{
			if (vars->file_map[0][j] != '1' || \
			vars->file_map[vars->win_draw.y - 1][j] != '1')
			{
				ft_putstr("wall is not valid\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	valid_waterv(vars);
}

void	valid_waterv(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->file_map[i])
	{
		j = 0;
		while (vars->file_map[i][j])
		{
			if (vars->file_map[i][vars->win_draw.x - 1] != '1')
			{
				ft_putstr("wall is not valid\n");
				exit(0);
			}
			if (vars->file_map[i][0] != '1')
			{
				ft_putstr("wall is not valid\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
