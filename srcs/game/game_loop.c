/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 12:44:17 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

char	*ft_get_path(int c)
{
	if (c == '1')
		return ("tileset/wall.xpm");
	if (c == '0')
		return ("tileset/ground.xpm");
	if (c == 'C')
		return ("tileset/coll.xpm");
	if (c == 'E')
		return ("tileset/exit.xpm");
	if (c == 'P')
		return ("tileset/player.xpm");
	return ("");
}

int	ft_draw_map(t_map *map, void *mlx, void *win)
{
	int		col;
	int		row;
	int		curr_x;
	int		curr_y;
	void	*img;
	int		width;
	int		height;

	width = 32;
	height = 32;
	curr_y = 0;
	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		curr_x = 0;
		while (++col < map->cols)
		{
			img = mlx_xpm_file_to_image(mlx, \
				ft_get_path(map->map[row][col]), &width, &height);
			if (!img)
				return (ERROR);
			mlx_put_image_to_window(mlx, win, img, curr_x, curr_y);
			curr_x += 32;
		}
		curr_y += 32;
	}
	return (0);
}

int	ft_game_loop(t_map *map)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->cols * 32, map->rows * 32, "so long");
	if (ft_draw_map(map, mlx, win) == ERROR)
		return (ERROR);
	mlx_loop(mlx);
	return (0);
}