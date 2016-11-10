/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 22:13:22 by jcapling          #+#    #+#             */
/*   Updated: 2016/10/18 11:58:25 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece		*ft_cord_xy(t_piece *block, char **str)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_piece				*ft_update_cord_xy(t_piece *block, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i != 4)
	{
		if (block->x[i] < xmin)
			xmin = block->x[i];
		if (block->y[i] < ymin)
			ymin = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - xmin + x;
		block->y[i] = block->y[i] - ymin + y;
		i++;
	}
	return (block);
}

t_piece				*ft_origin_xy(t_piece *block)
{
	t_piece		*holder;

	holder = block;
	while (block->next)
	{
		block = ft_cord_xy(block, ft_strsplit(block->str, '\n'));
		free(block->str);
		block = block->next;
	}
	return (holder);
}
