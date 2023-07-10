/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:37:32 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:16:46 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img(t_struct *game)
{
	game->b = mlx_xpm_file_to_image(game->mlx, "img/b.xpm",
			&game->img_w, &game->img_h);
	game->w = mlx_xpm_file_to_image(game->mlx, "img/w.xpm",
			&game->img_w, &game->img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "img/c.xpm",
			&game->img_w, &game->img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "img/e.xpm",
			&game->img_w, &game->img_h);
	game->p = mlx_xpm_file_to_image(game->mlx, "img/p.xpm",
			&game->img_w, &game->img_h);
}

static void	init_game(t_struct *game)
{
	game->collect = 0;
	game->action = 0;
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = height_len(game->map);
	game->p_x = 0;
	game->p_y = 0;
	game->win = NULL;
	game->mlx = mlx_init();
}

int	main(int argc, char **argv)
{
	t_struct	game;
	int			temp;
	int			fd;

	if (argc != 2)
		print_error("Argument Error!!!\n");
	fd = open(argv[1], O_RDONLY);
	game.map = read_map(fd);
	if (game.map == NULL)
		print_error("Parsing error\n");
	valid_map(&game);
	init_game(&game);
	init_img(&game);
	game.win = mlx_new_window(game.mlx, game.win_w * 32, game.win_h * 32,
			"so_long");
	temp = game.win_h;
	print_map(&game);
	game.win_h = temp;
	dfs_map_valid(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &key_hook, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &win_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
