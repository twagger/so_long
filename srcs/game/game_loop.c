/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 17:32:39 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#define ESC 53
#define TOP 13
#define BOTTOM 1
#define LEFT 0
#define RIGHT 2

void	ft_draw_map(t_map *map, void *mlx, void *win)
{
	int	col;
	int	row;
	int	img_i;
	int	curr_x;
	int	curr_y;

	curr_y = 0;
	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		curr_x = 0;
		while (++col < map->cols)
		{
			img_i = ft_strchr_index(AUTHORIZED, map->map[row][col], 0);
			mlx_put_image_to_window(mlx, win, map->img[0], curr_x, curr_y);
			mlx_put_image_to_window(mlx, win, map->img[img_i], curr_x, curr_y);
			curr_x += 32;
		}
		curr_y += 32;
	}
}

int	ft_handle_key(int key, void *param)
{
	if (key == ESC)
		exit(0);
	if (key == TOP)
		move_up(param);
	return (0);
}

int	ft_game_loop(t_map *map)
{
	void	*mlx;
	void	*win;
	t_param	param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->cols * 32, map->rows * 32, "so long");
	if (ft_init_imgs(map, mlx) == ERROR)
		return (ERROR);
	ft_draw_map(map, mlx, win);
	param.mlx = mlx;
	param.win = win;
	param.map = map;
	mlx_key_hook(win, ft_handle_key, &param);
	mlx_loop(mlx);
	return (0);
}
