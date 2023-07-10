/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:38:51 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:16:46 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define BUFFER_SIZE    42
# define KEY_PRESS		2
# define DESTROY_NOTIFY	17
# define W_KEYCODE		13
# define S_KEYCODE		1
# define A_KEYCODE		0
# define D_KEYCODE		2
# define ESC_KEYCODE	53
# define LEFT_KEYCODE	123
# define RIGHT_KEYCODE	124
# define UP_KEYCODE		126
# define DOWN_KEYCODE	125

typedef struct s_struct
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*b;
	void	*c;
	void	*w;
	void	*e;
	void	*p;
	int		win_w;
	int		win_h;
	int		p_x;
	int		p_y;
	int		action;
	int		collect;
	int		img_w;
	int		img_h;
	char	**map;
}				t_struct;

typedef struct s_dfs
{
	int	**visited;
	int	cnt_c;
	int	collect;
	int	exit;
}				t_dfs;

void	valid_map(t_struct *game);
void	print_map(t_struct *game);
void	set_dfs(t_struct *game, t_dfs *dfs);
void	dfs_map_valid(t_struct *game);
void	print_img(t_struct *game, int x, int y, void *img);
void	after_collect(t_struct *game);
void	print_error(char *s);
void	escape_door(t_struct *game);
int		ft_printf(const char *format, ...);
int		key_hook(int keycode, t_struct *game);
int		height_len(char **map);
int		win_exit(t_struct *game);
char	*get_next_line(int fd);
char	**read_map(int fd);
char	**map_free(t_struct *game);
char	**dfs_free(t_struct *game, int **visited);

#endif