/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:19:32 by woberon           #+#    #+#             */
/*   Updated: 2022/06/24 13:32:45 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr_bonus(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_bonus(n / 10);
		ft_putnbr_bonus(n % 10);
	}
}

void	ft_putstr_bonus(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	fd_open_bonus(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Fd no valid \n", 14);
		exit (0);
	}
	return (fd);
}
