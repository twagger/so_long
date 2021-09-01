/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/01 15:07:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long_bonus.h"

void	ft_do_move(t_player p, int move, t_param *param)
{
	int	next_x;
	int	next_y;

	next_x = p.x;
	next_y = p.y;
	if (move == UP)
		--next_y;
	if (move == RIGHT)
		++next_x;
	if (move == LEFT)
		--next_x;
	if (move == DOWN)
		++next_y;
	param->map->map[next_y][next_x] = 'P';
	param->map->map[p.y][p.x] = '0';
	mlx_put_image_to_window(param->mlx, param->win, \
		param->map->img[0], p.x * 32, p.y * 32);
	mlx_put_image_to_window(param->mlx, param->win, \
		param->map->img[0], next_x * 32, next_y * 32);
	mlx_put_image_to_window(param->mlx, param->win, \
		param->map->img[4], next_x * 32, next_y * 32);
	++(param->nb_moves);
}

char	ft_next_tile(t_player p, int move, t_map *map)
{
	if (move == UP)
		return (map->map[p.y - 1][p.x]);
	if (move == RIGHT)
		return (map->map[p.y][p.x + 1]);
	if (move == LEFT)
		return (map->map[p.y][p.x - 1]);
	if (move == DOWN)
		return (map->map[p.y + 1][p.x]);
	return ('X');
}

int	ft_move(t_param *param, int move)
{
	t_player	p;
	char		next;

	p = ft_get_player_pos(param->map);
	next = ft_next_tile(p, move, param->map);
	if (next == '0')
		ft_do_move(p, move, param);
	if (next == 'C')
	{
		ft_do_move(p, move, param);
		++(param->nb_items);
	}
	if (next == 'E')
	{
		if (param->nb_items == param->map->total_items)
		{
			ft_do_move(p, move, param);
			return (1);
		}
	}
	return (0);
}
