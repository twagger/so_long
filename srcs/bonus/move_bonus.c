/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/12 11:11:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_register_move(t_sprite p, int move, t_param *param, char next_tile)
{
	int	on_exit;

	on_exit = 0;
	param->move.nb_move = NBMOVES;
	param->move.x = p.x;
	param->move.y = p.y;
	ft_get_next_position(&p, move, next_tile);
	param->move.next_x = p.next_x;
	param->move.next_y = p.next_y;
	param->move.img[0] = param->img[(move * 3) + 5];
	param->move.img[1] = param->img[(move * 3) + 6];
	param->move.img[2] = param->img[(move * 3) + 7];
	if (next_tile == '1')
		return ;
	if (param->is_on_exit == 1)
		param->map->map[p.y][p.x] = 'E';
	else
		param->map->map[p.y][p.x] = '0';
	param->move.from_exit = param->is_on_exit;
	if (param->map->map[p.next_y][p.next_x] == 'E')
		on_exit = 1;
	param->is_on_exit = on_exit;
	param->move.to_exit = on_exit ;
	param->map->map[p.next_y][p.next_x] = 'P';
	++(param->curr_moves);
}

void	ft_erase_move_zone(t_param *param)
{
	ft_put_sprite(param->img[0], param->playground, \
		param->move.x * SSIZE, param->move.y * SSIZE);
	ft_put_sprite(param->img[0], param->playground, \
		param->move.next_x * SSIZE, param->move.next_y * SSIZE);
	if (param->move.from_exit)
		ft_put_sprite(param->img[3], param->playground, \
			param->move.x * SSIZE, param->move.y * SSIZE);
	if (param->move.to_exit)
		ft_put_sprite(param->img[3], param->playground, \
			param->move.next_x * SSIZE, param->move.next_y * SSIZE);
}

void	ft_do_move(t_param *param)
{
	int	x;
	int	y;

	if (param->move.nb_move == NBMOVES)
		param->keyblock = 1;
	ft_erase_move_zone(param);
	x = ft_calculate_sprite_pos(param->move.x, param->move.next_x, \
		param->move.nb_move);
	y = ft_calculate_sprite_pos(param->move.y, param->move.next_y, \
		param->move.nb_move);
	ft_put_sprite(param->move.img[param->move.next_img], \
		param->playground, x, y);
	++(param->move.next_img);
	if (param->move.next_img > 2)
		param->move.next_img = 0;
	--(param->move.nb_move);
	if (param->move.nb_move == 0)
		param->keyblock = 0;
}

int	ft_mover(t_param *param, int move)
{
	t_sprite	p;
	char		next;

	p = ft_get_player_pos(param->map);
	next = ft_get_next_tile(p, move, param->map);
	if (next == '1')
		ft_register_move(p, move, param, next);
	if (next == '0')
		ft_register_move(p, move, param, next);
	if (next == 'C')
	{
		ft_register_move(p, move, param, next);
		++(param->curr_items);
	}
	if (next == 'E')
	{
		if (param->curr_items == param->total_items)
		{
			ft_register_move(p, move, param, next);
			return (1);
		}
		else
			ft_register_move(p, move, param, next);
	}
	return (0);
}
