/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:05:02 by woberon           #+#    #+#             */
/*   Updated: 2022/06/24 13:35:40 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	free(str1);
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0)
		if (s[i--] == (char)c)
			return ((char *)s);
	return (NULL);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
