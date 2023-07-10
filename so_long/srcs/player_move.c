/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:54:54 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:33:39 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_struct *game)
{
	if ((game)->map[(game)->p_y][(game)->p_x] == 'E')
		print_img(game, game->p_x, game->p_y, game->w);
	else
		print_img(game, game->p_x, game->p_y, game->b);
	if ((game)->map[(game)->p_y - 1][(game)->p_x] == 'E')
	{
		if ((game)->collect == 0)
			escape_door(game);
		else
		{
			(game)->p_y -= 1;
			(game)->action++;
			print_img(game, game->p_x, game->p_y, game->p);
			return ;
		}
	}	
	else if ((game)->map[((game)->p_y) - 1][((game)->p_x)] != '1')
	{
		(game)->p_y -= 1;
		(game)->action++;
	}
	if ((game)->map[game->p_y][game->p_x] == 'C')
		after_collect(game);
	print_img(game, game->p_x, game->p_y, game->p);
}

static void	move_down(t_struct *game)
{
	if ((game)->map[(game)->p_y][(game)->p_x] == 'E')
		print_img(game, game->p_x, game->p_y, game->w);
	else
		print_img(game, game->p_x, game->p_y, game->b);
	if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		if (game->collect == 0)
			escape_door(game);
		else
		{	
			(game)->p_y += 1;
			(game)->action++;
			print_img(game, game->p_x, game->p_y, game->p);
			return ;
		}		
	}	
	else if (game->map[game->p_y + 1][game->p_x] != '1')
	{
		game->p_y += 1;
		game->action++;
	}
	if (game->map[game->p_y][game->p_x] == 'C')
		after_collect(game);
	print_img(game, game->p_x, game->p_y, game->p);
}

static void	move_left(t_struct *game)
{
	if ((game)->map[(game)->p_y][(game)->p_x] == 'E')
		print_img(game, game->p_x, game->p_y, game->w);
	else
		print_img(game, game->p_x, game->p_y, game->b);
	if (game->map[game->p_y][game->p_x - 1] == 'E')
	{
		if (game->collect == 0)
			escape_door(game);
		else
		{	
			(game)->p_x -= 1;
			(game)->action++;
			print_img(game, game->p_x, game->p_y, game->p);
			return ;
		}		
	}	
	else if (game->map[game->p_y][game->p_x - 1] != '1')
	{
		game->p_x -= 1;
		game->action++;
	}
	if (game->map[game->p_y][game->p_x] == 'C')
		after_collect(game);
	print_img(game, game->p_x, game->p_y, game->p);
}

static void	move_right(t_struct *game)
{
	if ((game)->map[(game)->p_y][(game)->p_x] == 'E')
		print_img(game, game->p_x, game->p_y, game->w);
	else
		print_img(game, game->p_x, game->p_y, game->b);
	if (game->map[game->p_y][game->p_x + 1] == 'E')
	{
		if (game->collect == 0)
			escape_door(game);
		else
		{	
			(game)->p_x += 1;
			(game)->action++;
			print_img(game, game->p_x, game->p_y, game->p);
			return ;
		}		
	}	
	else if (game->map[game->p_y][game->p_x + 1] != '1')
	{
		game->p_x += 1;
		game->action++;
	}
	if (game->map[game->p_y][game->p_x] == 'C')
		after_collect(game);
	print_img(game, game->p_x, game->p_y, game->p);
}

int	key_hook(int keycode, t_struct *game)
{
	int	cnt_move;

	cnt_move = game->action;
	if (keycode == W_KEYCODE || keycode == UP_KEYCODE)
		move_up(game);
	else if (keycode == S_KEYCODE || keycode == DOWN_KEYCODE)
		move_down(game);
	else if (keycode == A_KEYCODE || keycode == LEFT_KEYCODE)
		move_left(game);
	else if (keycode == D_KEYCODE || keycode == RIGHT_KEYCODE)
		move_right(game);
	else if (keycode == ESC_KEYCODE)
		map_free(game);
	if (cnt_move != game->action)
		ft_printf("move count = %d\n", game->action);
	return (0);
}
