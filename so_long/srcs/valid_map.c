/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:55:48 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 14:59:07 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	valid_top_and_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	valid_elements(t_struct **game)
{
	int	count;
	int	num_c;
	int	x;
	int	y;

	count = 0;
	num_c = 0;
	y = height_len((*game)->map) - 1;
	while (y)
	{
		x = 0;
		while ((*game)->map[y][x])
		{
			if ((*game)->map[y][x] == 'E' || (*game)->map[y][x] == 'P')
				count++;
			else if ((*game)->map[y][x] == 'C')
				num_c++;
			x++;
		}
		y--;
	}
	if (count != 2 || num_c < 1)
		print_error("elements error!!\n");
}

static void	valid_surround(t_struct **game)
{
	int	i;
	int	j;

	if (valid_top_and_bottom((*game)->map[0]))
		print_error("Up-map not surrounded!!\n");
	j = height_len((*game)->map) - 1;
	i = 0;
	while (i < j)
	{
		if ((*game)->map[i][0] != '1' ||
			(*game)->map[i][ft_strlen((*game)->map[i]) - 1] != '1')
			print_error("Side-map not surrounded!!\n");
		i++;
	}
	if (valid_top_and_bottom((*game)->map[j]))
		print_error("Down-map not surrouded!!\n");
}	

static void	valid_rectangle(t_struct **game)
{
	int	height;
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	height = height_len((*game)->map);
	while (y < height)
	{
		x = 0;
		while ((*game)->map[y][x])
			x++;
		if (count != 0)
		{
			if (count != x)
				print_error("Not rectangular!!\n");
		}
		else
			count = x;
		y++;
	}
}

void	valid_map(t_struct *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'E' &&
				game->map[i][j] != '0' && game->map[i][j] != 'P' &&
				game->map[i][j] != 'C')
				print_error("another element\n");
			j++;
		}
		i++;
	}
	valid_rectangle(&game);
	valid_surround(&game);
	valid_elements(&game);
}
