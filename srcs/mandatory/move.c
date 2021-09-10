/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/10 11:49:07 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_next_position(t_sprite *p, int move)
{
	p->next_x = p->x;
	p->next_y = p->y;
	if (move == UP)
		--(p->next_y);
	if (move == RIGHT)
		++(p->next_x);
	if (move == LEFT)
		--(p->next_x);
	if (move == DOWN)
		++(p->next_y);
}

char	ft_get_next_tile(t_sprite p, int move, t_map *map)
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

void	ft_do_move(t_sprite p, int move, t_param *param)
{
	ft_get_next_position(&p, move);
	ft_draw_image(param, param->img[0], p.x, p.y);
	if (param->is_on_exit == 1)
	{
		ft_draw_image(param, param->img[3], p.x, p.y);
		param->map->map[p.y][p.x] = 'E';
	}
	else
		param->map->map[p.y][p.x] = '0';
	if (param->map->map[p.next_y][p.next_x] == 'E')
		param->is_on_exit = 1;
	else
	{
		ft_draw_image(param, param->img[0], p.next_x, p.next_y);
		param->is_on_exit = 0;
	}
	ft_draw_image(param, param->img[4], p.next_x, p.next_y);
	param->map->map[p.next_y][p.next_x] = 'P';
	++(param->curr_moves);
}

int	ft_mover(t_param *param, int move)
{
	t_sprite	p;
	char		next;

	p = ft_get_player_pos(param->map);
	next = ft_get_next_tile(p, move, param->map);
	if (next == '0')
		ft_do_move(p, move, param);
	if (next == 'C')
	{
		ft_do_move(p, move, param);
		++(param->curr_items);
	}
	if (next == 'E')
	{
		if (param->curr_items == param->total_items)
		{
			ft_do_move(p, move, param);
			return (1);
		}
		else
			ft_do_move(p, move, param);
	}
	return (0);
}
