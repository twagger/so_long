/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:03:14 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 10:45:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_line(t_map *map, char *line)
{
	int	i;

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

int	ft_map_creator(int fd, t_map *map, int rows)
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
		return (ft_free_map(map, ERROR));
	else
		ft_add_line(map, line);
	return (0);
}
