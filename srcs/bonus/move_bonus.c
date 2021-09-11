/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/11 15:33:27 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_sprite	ft_get_player_pos(t_map *map)
{
	int			i;
	int			j;
	t_sprite	player;

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
	player.y = TOP_GAP * SSIZE;
	return (player);
}

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
	// tourner le personnage dans la bonne direction sur place et mettre 
	//  dans le param le move a faire pour qu'il soit joue par le loop hook
	//	mettre a jour la carte
	// 
	// Creer une nouvelle structure a ratacher au param t_move : img[3], nb_moves, x, y, next_x, next_y
}

void	ft_do_move_old(t_sprite p, int move, t_param *param)
{
	ft_get_next_position(&p, move);
	ft_put_sprite(param->img[0], param->playground, p.x * SSIZE, p.y * SSIZE);
	if (param->is_on_exit == 1)
	{
		ft_put_sprite(param->img[3], param->playground, \
			p.x * SSIZE, p.y * SSIZE);
		param->map->map[p.y][p.x] = 'E';
	}
	else
		param->map->map[p.y][p.x] = '0';
	if (param->map->map[p.next_y][p.next_x] == 'E')
		param->is_on_exit = 1;
	else
	{
		ft_put_sprite(param->img[0], param->playground, \
			p.next_x * SSIZE, p.next_y * SSIZE);
		param->is_on_exit = 0;
	}
	ft_put_sprite(param->img[4], param->playground, \
		p.next_x * SSIZE, p.next_y * SSIZE);
	param->map->map[p.next_y][p.next_x] = 'P';
	mlx_put_image_to_window(param->mlx, param->win, \
		param->playground->img, 0, TOP_GAP);
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
