/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:57:43 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 14:00:47 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *s)
{
	perror(s);
	exit(1);
}

int	win_exit(t_struct *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
	return (0);
}

void	escape_door(t_struct *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

char	**map_free(t_struct *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

char	**dfs_free(t_struct *game, int **visited)
{
	int	i;

	i = 0;
	while (i < game->win_h)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (NULL);
}
