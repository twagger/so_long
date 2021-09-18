/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:45:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 14:59:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#define W 13
#define S 1
#define A 0
#define D 2
#define KEYMAP "321----------0"

void	ft_register_ennemy_moves(t_param *prm)
{
	ft_register_move('U', prm, KEYMAP[W] - 48);
	ft_register_move('L', prm, KEYMAP[A] - 48);
	ft_register_move('D', prm, KEYMAP[S] - 48);
	ft_register_move('R', prm, KEYMAP[D] - 48);
}

void	ft_register_move(char type, t_param *prm, int move)
{
	t_mob	*begin;
	char	next_tile;

	begin = prm->mobs;
	while (prm->mobs)
	{
		if (prm->mobs->type == type && prm->mobs->nb_move == 0)
		{
			next_tile = ft_get_next_tile(prm->mobs->x, prm->mobs->y, \
				move, prm->map);
			if (ft_strchr(MOBS, next_tile))
			{
				if (type == 'P' || ft_strchr_index(MOBS, next_tile, 0) == 0)
					prm->endgame = 2;
				next_tile = '1';
			}
			ft_get_next_position(prm->mobs, move, next_tile);
			prm->mobs->nb_move = NBMOVES;
			prm->mobs->move = move;
			ft_update_map_array(prm->mobs, prm);
			if (next_tile == '1')
			{
				if (type == 'R')
				 	prm->mobs->type = 'L';
				if (type == 'L')
				 	prm->mobs->type = 'R';
				if (type == 'U')
				 	prm->mobs->type = 'D';
				if (type == 'D')
				 	prm->mobs->type = 'U';
			}
			if (next_tile != '1' && type == 'P')
				++(prm->curr_moves);
		}
		prm->mobs = prm->mobs->next;
	}
	prm->mobs = begin;
}

void	ft_update_move_zone(t_param *prm, t_mob *m)
{
	ft_put_sprite(prm->img[0], prm->playground, m->x * SSIZE, m->y * SSIZE);
	ft_put_sprite(prm->img[0], prm->playground, \
		m->next_x * SSIZE, m->next_y * SSIZE);
	if (m->from_exit)
		ft_put_sprite(prm->img[3], prm->playground, \
			m->x * SSIZE, m->y * SSIZE);
	if (m->to_exit)
		ft_put_sprite(prm->img[3], prm->playground, \
			m->next_x * SSIZE, m->next_y * SSIZE);
	if (m->from_coll)
		ft_put_sprite(prm->img[2], prm->playground, \
			m->x * SSIZE, m->y * SSIZE);
	if (m->to_coll)
		ft_put_sprite(prm->img[2], prm->playground, \
			m->next_x * SSIZE, m->next_y * SSIZE);
}

void	ft_move_mobs(t_param *prm)
{
	int		x;
	int		y;
	int		img_i;
	t_mob	*begin;

	begin = prm->mobs;
	while (prm->mobs)
	{
		if (prm->mobs->nb_move != 0)
		{
			if (prm->mobs->type == 'P' && prm->mobs->nb_move == NBMOVES)
				prm->keyblock = 1;
			ft_update_move_zone(prm, prm->mobs);
			x = ft_get_pos(prm->mobs->x, prm->mobs->next_x, prm->mobs->nb_move);
			y = ft_get_pos(prm->mobs->y, prm->mobs->next_y, prm->mobs->nb_move);
			img_i = ft_strchr_index(AUTHORIZED, prm->mobs->type, 0);
			if (img_i > 4)
				img_i = (3 * img_i) + 2;
			else
				img_i += (3 * prm->mobs->move) + 1;	
			ft_put_sprite(prm->img[img_i + prm->mobs->next_img], \
				prm->playground, x, y);
			if (++(prm->mobs->next_img) > 2)
				prm->mobs->next_img = 0;
			if (--(prm->mobs->nb_move) == 0)
			{
				prm->mobs->x = prm->mobs->next_x;
				prm->mobs->y = prm->mobs->next_y;
				prm->mobs->from_exit = prm->mobs->to_exit;
				prm->mobs->from_coll = prm->mobs->to_coll;
			}
		}
		prm->mobs = prm->mobs->next;
	}
	prm->mobs = begin;
}
