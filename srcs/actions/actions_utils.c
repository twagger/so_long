/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:49:01 by twagner           #+#    #+#             */
/*   Updated: 2021/09/01 09:12:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	ft_get_player_pos(t_map *map)
{
	int			i;
	int			j;
	t_player	player;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
				return (player);
			}
		}
	}
	player.x = 0;
	player.y = 0;
	return (player);
}
