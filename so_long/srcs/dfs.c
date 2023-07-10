/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:39:18 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:16:46 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	escape_check(t_struct *game, t_dfs *dfs, int x, int y)
{
	if (game->map[y][x] == '1' || dfs->visited[y][x] == 1 || dfs->exit != 1)
		return (0);
	if (game->map[y][x] == 'E')
		dfs->exit--;
	dfs->visited[y][x] = 1;
	return (1);
}

static void	escape_dfs(t_struct *game, t_dfs *dfs, int x, int y)
{
	if (escape_check(game, dfs, x + 1, y))
		escape_dfs(game, dfs, x + 1, y);
	if (escape_check(game, dfs, x - 1, y))
		escape_dfs(game, dfs, x - 1, y);
	if (escape_check(game, dfs, x, y + 1))
		escape_dfs(game, dfs, x, y + 1);
	if (escape_check(game, dfs, x, y - 1))
		escape_dfs(game, dfs, x, y - 1);
}

static int	collect_check(t_struct *game, t_dfs *dfs, int x, int y)
{
	if (game->map[y][x] == '1' || dfs->visited[y][x] == 1 || !dfs->collect)
		return (0);
	if (game->map[y][x] == 'C')
		dfs->collect--;
	dfs->visited[y][x] = 1;
	return (1);
}

static void	collect_dfs(t_struct *game, t_dfs *dfs, int x, int y)
{
	if (collect_check(game, dfs, x + 1, y))
		collect_dfs(game, dfs, x + 1, y);
	if (collect_check(game, dfs, x - 1, y))
		collect_dfs(game, dfs, x - 1, y);
	if (collect_check(game, dfs, x, y + 1))
		collect_dfs(game, dfs, x, y + 1);
	if (collect_check(game, dfs, x, y - 1))
		collect_dfs(game, dfs, x, y - 1);
}

void	dfs_map_valid(t_struct *game)
{
	t_dfs	dfs;

	set_dfs(game, &dfs);
	collect_dfs(game, &dfs, game->p_x, game->p_y);
	if (dfs.collect != 0)
		print_error("DFS_Error collect");
	dfs_free(game, dfs.visited);
	set_dfs(game, &dfs);
	escape_dfs(game, &dfs, game->p_x, game->p_y);
	if (dfs.exit != 0)
		print_error("DFS_Error exit");
	dfs_free(game, dfs.visited);
}
