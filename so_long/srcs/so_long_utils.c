/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:43:57 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 14:57:24 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	height_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	set_dfs(t_struct *game, t_dfs *dfs)
{
	int	i;
	int	j;

	dfs->collect = game->collect;
	dfs->exit = 1;
	dfs->visited = (int **)malloc(sizeof(int *) * game->win_h);
	if (!dfs->visited)
		print_error("Malloc Error!!\n");
	i = 0;
	while (i < game->win_h)
	{
		dfs->visited[i] = malloc(sizeof(int) * game->win_w);
		if (!dfs->visited[i])
			print_error("Malloc Error!!\n");
		j = 0;
		while (j < game->win_w)
		{
			dfs->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	seperate_map_check(char *final_line)
{
	int	i;
	int	j;

	i = 0;
	while (final_line[i])
	{
		if (final_line[i] == '1' && final_line[i + 1] == '\n'
			&&final_line[i + 2] == '\n')
		{
			j = i + 2;
			while (final_line[j])
			{
				if (final_line[j] == '1')
					print_error("map error!!\n");
				j++;
			}
		}
		i++;
	}
}

char	**read_map(int fd)
{
	char	*line;
	char	*final_line;
	char	**ret;
	char	*tmp;

	final_line = NULL;
	if (fd < 0)
		print_error("fd error!!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = final_line;
		final_line = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	if (final_line == NULL)
		print_error("gnl error!!\n");
	seperate_map_check(final_line);
	ret = ft_split(final_line, '\n');
	free(final_line);
	return (ret);
}
