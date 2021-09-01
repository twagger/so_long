/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:11:47 by twagner           #+#    #+#             */
/*   Updated: 2021/09/01 17:57:38 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <string.h>
#include <errno.h>
#include "so_long.h"

int	ft_is_map_valid(char *map_file, int *rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (-1);
	if (ft_map_controler(fd, rows) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_is_ber_file(char *map_file)
{
	int	dot_pos;

	dot_pos = ft_strchr_index(map_file, '.', -1);
	if (dot_pos == ERROR)
		return (0);
	else
	{	
		if ((ft_strncmp(map_file + dot_pos, ".ber", 5)) == 0 \
			&& (dot_pos != 0) \
			&& (*(map_file + dot_pos - 1) != '/'))
			return (1);
		else
			return (0);
	}
}

int	ft_file_to_array(char *map_file, t_map *map, int rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (0);
	if (ft_create_map(fd, map, rows) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_game_loop(t_map *map)
{
	void	*mlx;
	void	*win;
	t_param	param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->cols * 32, map->rows * 32, "so long");
	if (ft_init_imgs(map, mlx) == ERROR)
		return (ft_free_map(map, ERROR, mlx));
	ft_draw_map(map, mlx, win);
	param.mlx = mlx;
	param.win = win;
	param.map = map;
	param.nb_items = 0;
	param.nb_moves = 0;
	mlx_hook(win, 2, 1L << 0, ft_handle_key, &param);
	mlx_hook(win, 17, 0L, ft_handle_close, &param);
	mlx_loop(mlx);
	return (ft_free_map(map, 0, mlx));
}

int	main(int ac, char **av)
{
	int		rows;
	int		map_check;
	t_map	map;

	rows = 1;
	if (ac != 2)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	if (!ft_is_ber_file(av[1]))
		return (ft_exit_w_message("Error", "File is not a BER file", 2, 1));
	map_check = ft_is_map_valid(av[1], &rows);
	if (map_check == ERROR)
		return (ft_exit_w_message("Error", strerror(errno), 2, 1));
	else if (!map_check)
		return (ft_exit_w_message("Error", "MAP is not valid", 2, 1));
	if (ft_file_to_array(av[1], &map, rows) == ERROR)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	if (ft_game_loop(&map) == ERROR)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	return (0);
}
