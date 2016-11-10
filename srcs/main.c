/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:40:54 by jcapling          #+#    #+#             */
/*   Updated: 2016/10/25 20:00:08 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read(char *file)
{
	int		fd;
	int		read_status;
	int		i;
	char	tmp[545];
	char	buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((read_status = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			ft_error();
	}
	tmp[i] = '\0';
	if(close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

t_piece		*ft_store(char *str)
{
	int			i;
	int			k;
	char		c;
	t_piece		*block;
	t_piece		*holder;

	k = 0;
	c = 64;
	i = ft_basic_checker(str);
	if (!(block = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	holder = block;
	while (i-- > 0)
	{
		holder->str = ft_strndup(&str[k], 20);
		ft_extended_checker(holder->str);
		holder->c = ++c;
		k += 21;
		if (!(holder->next = (t_piece *)malloc(sizeof(t_piece))))
			return (NULL);
		holder = holder->next;
	}
	holder->next = NULL;
	return (block);
}

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit (0);
}

int			main(int argc, char **argv)
{
	char	*reader;
	t_piece	*block;
	char	**result;

	if (argc != 2)
		ft_error();
	reader = ft_read(argv[1]);
	block = ft_store(reader);
	block = ft_origin_xy(block);
	result = ft_result(block, ft_max(block));
	free(block);
	while (*result)
		ft_putendl(*result++);
	return (0);
}
