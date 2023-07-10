/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:56:41 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:17:58 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	after_collect(t_struct *game)
{
	game->collect--;
	game->map[game->p_y][game->p_x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->b,
		game->p_x * 32, game->p_y * 32);
}

void	print_img(t_struct *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

static void	map_to_img(char c, int x, int y, t_struct *game)
{
	if (c == '1')
		print_img(game, x, y, game->e);
	else if (c == 'E')
	{	
		print_img(game, x, y, game->b);
		print_img(game, x, y, game->w);
	}	
	else if (c == 'C')
	{
		print_img(game, x, y, game->b);
		print_img(game, x, y, game->c);
		(game)->collect++;
	}
	else if (c == 'P')
	{
		(game)->p_y = y;
		(game)->p_x = x;
		print_img(game, x, y, game->b);
		print_img(game, x, y, game->p);
	}
	else
		print_img(game, x, y, game->b);
}

void	print_map(t_struct *game)
{
	int	x_map;
	int	y_map;
	int	x;
	int	y;
	int	temp_w;

	y = 0;
	y_map = 0;
	temp_w = game->win_w;
	while (game->win_h > 0)
	{
		x = 0;
		x_map = 0;
		while (game->win_w > 0)
		{
			map_to_img(game->map[y_map][x_map], x, y, game);
			x_map++;
			x += 1;
			game->win_w--;
		}
		game->win_w = temp_w;
		y_map++;
		y += 1;
		game->win_h--;
	}
}
