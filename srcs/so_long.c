/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:11:47 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 10:45:41 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

int	ft_create_map(char *map_file, t_map *map, int rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (0);
	if (ft_map_creator(fd, map, rows) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_is_map_valid(char *map_file, int *rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (0);
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

int	main(int ac, char **av)
{
	int		rows;
	t_map	map;

	rows = 1;
	if (ac != 2)
		return (ft_exit_w_message("Error", 2, 1));
	if (!ft_is_ber_file(av[1]))
		return (ft_exit_w_message("Error", 2, 1));
	if (!ft_is_map_valid(av[1], &rows))
		return (ft_exit_w_message("Error", 2, 1));
	if (ft_create_map(av[1], &map, rows) == ERROR)
		return (ft_exit_w_message("Error", 2, 1));
	return (ft_free_map(&map, 0));
}
