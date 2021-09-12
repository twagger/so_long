/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/12 09:55:31 by twagner          ###   ########.fr       */
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

int	ft_calculate_sprite_pos(int curr, int next, int n)
{
	if (curr == next)
		return (curr * SSIZE);
	if (next > curr)
		return ((((next * SSIZE) - (curr * SSIZE)) / NBMOVES) \
			* (NBMOVES - n) + (curr * SSIZE));
	if (curr > next)
		return ((curr * SSIZE) - ((((curr * SSIZE) - (next * SSIZE)) \
			/ NBMOVES) * (NBMOVES - n)));
	return (-1);
}
