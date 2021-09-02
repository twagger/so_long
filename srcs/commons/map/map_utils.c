/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:23:43 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 09:58:27 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

int	ft_free_map(t_map *map, int ret_code, void *mlx)
{
	int	i;

	if (map)
	{
		if (map->map)
		{
			i = -1;
			while (++i < map->rows)
				free(map->map[i]);
		}
		if (map->img)
		{
			i = -1;
			while (++i < NBSPRITES)
			{
				if (mlx)
					mlx_destroy_image(mlx, map->img[i]);
				else
					free(map->img[i]);
			}
			free(map->img);
		}
	}
	return (ret_code);
}

int	ft_init_map(t_map *map, int rows)
{
	int	i;

	map->map = (char **)malloc(sizeof(map->map) * rows);
	if (!map->map)
		return (ERROR);
	i = -1;
	while (++i < rows)
		map->map[i] = NULL;
	map->rows = rows;
	map->cols = 0;
	map->total_items = 0;
	map->img = NULL;
	return (0);
}

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
			curr_x += SSIZE;
		}
		curr_y += SSIZE;
	}
}

void	ft_add_line(t_map *map, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'C')
			++(map->total_items);
	}
	i = -1;
	while (++i < map->rows)
	{
		if (!map->map[i])
		{
			map->map[i] = line;
			break ;
		}
	}
	if (map->cols == 0)
		map->cols = ft_strlen(line);
}

int	ft_create_map(int fd, t_map *map, int rows)
{
	int		ret;
	char	*line;

	if (ft_init_map(map, rows) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		ft_add_line(map, line);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	if (ret == ERROR)
		return (ft_free_map(map, ERROR, NULL));
	else
		ft_add_line(map, line);
	return (0);
}
