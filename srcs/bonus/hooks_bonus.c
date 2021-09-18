/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 14:59:45 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#define ESC 53
#define W 13
#define S 1
#define A 0
#define D 2
#define KEYMAP "321----------0"

int	ft_handle_key(int key, void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	if (key == ESC)
	{
		ft_free_mem(prm->map, prm, prm->mlx, 0);
		exit(0);
	}
	/* */
	int	col;
	int	row;
	if (key == 9) // V
	{
		row = -1;
		while (++row < prm->map->rows)
		{
			col = -1;
			while (++col < prm->map->cols)
			{
				printf("%c", prm->map->map[row][col]);
			}
			printf("\n");
		}
		printf("\n");
	}
	/* */
	if (key == W || key == S || key == A || key == D)
	{
		if (prm->keyblock == 0)
			ft_register_move('P', param, KEYMAP[key] - 48);
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	ft_free_mem(prm->map, prm, prm->mlx, 0);
	exit(0);
	return (0);
}

void	ft_unfreeze_player(t_param *prm)
{
	t_mob	*begin;

	begin = prm->mobs;
	while (prm->mobs)
	{
		if (prm->mobs->type == 'P' && prm->mobs->nb_move == 0)
			prm->keyblock = 0;
		prm->mobs = prm->mobs->next;
	}
	prm->mobs = begin;
}

int	ft_render_next_frame(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	if (prm->frames > 1000)
		prm->frames = 0;
	++(prm->frames);
	ft_unfreeze_player(prm);
	if (prm->frames % 3 == 0)
	{
		ft_move_mobs(prm);
		ft_register_ennemy_moves(prm);
	}
	if (prm->endgame > 0)
	{
		if (prm->endgame == 1)
			ft_endgame(prm, "You win !");
		if (prm->endgame == 2)
			ft_endgame(prm, "You lose !");
		return (0);
	}
	if (ft_update_infoscore(prm) == ERROR)
		return (ERROR);
	mlx_put_image_to_window(prm->mlx, prm->win, \
		prm->playground->img, 0, TOP_GAP);
	return (0);
}
