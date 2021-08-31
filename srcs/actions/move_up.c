/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 17:52:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	move_up(t_param *param)
{
	t_player	player;

	player = ft_get_player_pos(param->map);
	if (param->map->map[player.y - 1][player.x] == '0')
	{
		param->map->map[player.y - 1][player.x] = 'P';
		param->map->map[player.y][player.x] = '0';
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], player.x * 32, player.y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[4], player.x * 32, (player.y - 1) * 32);
		return (0);
	}
	if (param->map->map[player.y - 1][player.x] == '1')
		return (0);
	if (param->map->map[player.y - 1][player.x] == 'C')

	if (param->map->map[player.y - 1][player.x] == 'E')
	{
		if (param->nb_items == param->map->total_items)
			exit(0);
		else
			return (0);
	}
	return (0);
}