/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:51:07 by jcapling          #+#    #+#             */
/*   Updated: 2016/10/18 11:59:27 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_fill_blank(char **str, int max_num)
{
	int		x;
	int		y;

	y = 0;
	while (!(str = (char **)malloc(sizeof(char *) * (max_num + 1))))
		return (NULL);
	while (y < max_num)
	{
		str[y] = ft_strnew(max_num);
		x = 0;
		while (x < max_num)
		{
			str[y][x] = '.';
			x++;
		}
		y++;
	}
	str[y] = NULL;
	return (str);
}

int			ft_max(t_piece *block)
{
	int		i;
	int		max_num;

	i = 0;
	max_num = 2;
	while (block->next && i++)
		block = block->next;
	while (max_num * max_num < i * 4)
		max_num++;
	return (max_num);
}
