/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 21:43:48 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_mob	ft_get_player_pos(t_map *map)
{
	int		i;
	int		j;
	t_mob	player;

	player.type = 'P';
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

void	ft_get_next_position(t_mob *m, int move, char next_tile)
{
	m->next_x = m->x;
	m->next_y = m->y;
	if (next_tile == '1')
		return ;
	if (move == ft_getmove(K_UP))
		--(m->next_y);
	if (move == ft_getmove(K_RIGHT))
		++(m->next_x);
	if (move == ft_getmove(K_LEFT))
		--(m->next_x);
	if (move == ft_getmove(K_DOWN))
		++(m->next_y);
}

char	ft_get_next_tile(int x, int y, int move, t_map *map)
{
	if (move == ft_getmove(K_UP))
		return (map->map[y - 1][x]);
	if (move == ft_getmove(K_RIGHT))
		return (map->map[y][x + 1]);
	if (move == ft_getmove(K_LEFT))
		return (map->map[y][x - 1]);
	if (move == ft_getmove(K_DOWN))
		return (map->map[y + 1][x]);
	return ('X');
}

int	ft_get_pos(int curr, int next, int n)
{
	if (curr == next)
		return (curr * SSIZE);
	if (next > curr)
		return ((((next * SSIZE) - (curr * SSIZE)) / NBMOVES) \
			* (NBMOVES - n + 1) + (curr * SSIZE));
	if (curr > next)
		return ((curr * SSIZE) - ((((curr * SSIZE) - (next * SSIZE)) \
			/ NBMOVES) * (NBMOVES - n + 1)));
	return (-1);
}

void	ft_update_map_array(t_mob *m, t_param *prm, char next_tile)
{
	if (m->from_exit)
		prm->map->map[m->y][m->x] = 'E';
	else if (m->from_coll && m->type != 'P')
		prm->map->map[m->y][m->x] = 'C';
	else
		prm->map->map[m->y][m->x] = '0';
	m->to_exit = (prm->map->map[m->next_y][m->next_x] == 'E');
	m->to_coll = (prm->map->map[m->next_y][m->next_x] == 'C');
	if (m->to_coll && m->type == 'P')
	{
		m->to_coll = 0;
		++(prm->curr_items);
		prm->map->map[m->next_y][m->next_x] = '0';
	}
	if (m->type == 'P' && m->to_exit && prm->curr_items == prm->total_items)
		prm->endgame = 1;
	if (m->type == 'P' && next_tile != '1')
		++(prm->curr_moves);
	prm->map->map[m->next_y][m->next_x] = m->type;
}
