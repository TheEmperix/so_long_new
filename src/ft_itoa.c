/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:18:55 by woberon           #+#    #+#             */
/*   Updated: 2022/03/09 11:20:19 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_value(int n)

{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_len(int n)

{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)

{
	char	*res;
	int		l;

	l = ft_len(n);
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--l;
		res[l] = ft_value(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
