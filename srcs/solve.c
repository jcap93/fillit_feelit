/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:22:39 by jcapling          #+#    #+#             */
/*   Updated: 2016/10/18 12:01:53 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_reset(char **holder, t_piece *block, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (holder[y][x] == block->c)
				holder[y][x] = '.';
			x++;
		}
		y++;
	}
	return (holder);
}

static char		**ft_save(char **holder, t_piece *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				holder[y][x] = block->c;
				i++;
			}
			x++;
		}
		holder[y][x] = '\0';
		y++;
	}
	holder[y] = NULL;
	return (holder);
}

static int		ft_check(char **holder, t_piece *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y && holder[y][x] == '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char		**ft_solve(char **holder, t_piece *block, int max)
{
	int		x;
	int		y;
	char	**str;

	if (!block->next)
		return (holder);
	str = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			block = ft_update_cord_xy(block, x, y);
			if (ft_check(holder, block, max))
				str = ft_solve(ft_save(holder, block, max), block->next, max);
			if (str)
				return (str);
			holder = ft_reset(holder, block, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(t_piece *block, int max)
{
	char	**holder;

	holder = NULL;
	while (!holder)
	{
		holder = ft_fill_blank(holder, max);
		holder = ft_solve(holder, block, max);
		max++;
	}
	return (holder);
}
