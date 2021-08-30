/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:11:47 by twagner           #+#    #+#             */
/*   Updated: 2021/08/30 15:12:37 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

int	ft_is_map_valid(char *map_file)
{
	int 	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (0);
	if (ft_map_controler(fd) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_exit_w_message(char *message, int fd, int code)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	return (code);
}

int ft_is_ber_file(char *map_file)
{
	int dot_pos;

	dot_pos = ft_strchr_index(map_file, '.', 0);
	if (dot_pos == ERROR)
		return (0);
	else
	{	
		if ((ft_strncmp(map_file + dot_pos, "ber", 4)) == 0)
			return (1);
		else
			return (0);		
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_exit_w_message("Error", 2, 1));
	if (!ft_is_ber_file(av[1]))
		return (ft_exit_w_message("Error", 2, 1));
	if (!ft_is_map_valid(av[1]))
		return (ft_exit_w_message("Error", 2, 1));
	ft_putstr_fd("map ok\n", 1);
	// read the file and load the entire map
	// display the game
	return (0);
}