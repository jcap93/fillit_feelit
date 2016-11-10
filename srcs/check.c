/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:37:31 by jcapling          #+#    #+#             */
/*   Updated: 2016/10/25 17:15:26 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_convertx(int i, char *str)
{
	if (str[i + 1] == '#')
	{
		str[i + 1] = 'x';
		str = ft_convertx(i + 1, str);
	}
	if (str[i - 1] >= 0 && str[i - 1] == '#')
	{
		str[i - 1] = 'x';
		str = ft_convertx(i - 1, str);
	}
	if (str[i + 5] <= 20 && str[i + 5] == '#')
	{
		str[i + 5] = 'x';
		str = ft_convertx(i + 5, str);
	}
	if (str[i - 5] >= 0 && str[i - 5] == '#')
	{
		str[i -5] = 'x';
		str = ft_convertx(i - 5, str);
	}
	if (str[i] == '#')
		str[i] = 'x';
	return (str);
}

static int		ft_countx(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == 'x')
			count++;
		str++;
	}
	return (count);
}

void			ft_extended_checker(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	str[i] = 'x';
	str = ft_convertx(i, str);
	if (ft_countx(str) != 4)
		ft_error();
	while (*str)
	{
		if (*str == 'x')
			*str = '#';
		str++;
	}	
}

int				ft_basic_checker(char *reading)
{
	int		dot;
	int		hash;
	int		endl;

	dot = 0;
	hash = 0;
	endl = 0;
	while (*reading)
	{
		if (*reading == '.')
			dot++;
		else if (*reading == '#')
			hash++;
		else if (*reading == '\n')
			endl++;
		else
			ft_error();
		reading++;
	}
	if (hash < 4)
		ft_error();
	if (dot % 4 || hash % 4 || (endl + 1) % 5)
		ft_error();
	return (hash / 4);
}
