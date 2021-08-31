/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:23:43 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 10:45:29 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_map(t_map *map, int ret_code)
{
	int	i;

	i = -1;
	if (map)
		while (++i < map->rows)
			free(map->map[i]);
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
	return (0);
}
