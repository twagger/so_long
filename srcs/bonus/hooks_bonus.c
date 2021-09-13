/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/13 15:10:49 by twagner          ###   ########.fr       */
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
	if (key == W || key == S || key == A || key == D)
	{
		if (prm->keyblock == 0)
			prm->endgame = ft_mover(param, KEYMAP[key] - 48);
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

int	ft_render_next_frame(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	if (prm->frames > 1000)
		prm->frames = 0;
	++(prm->frames);
	if (prm->frames % 3 == 0)
	{
		ft_move_patrol(prm);
		if (prm->move.nb_move > 0)
			ft_do_move(prm);
	}
	if (prm->endgame > 0)
	{
		if (prm->endgame == 1)
			ft_endgame(prm, "You win !");
		if (prm->endgame == 2)
			ft_endgame(prm, "You lose!");
		return (0);
	}
	ft_update_infoscore(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, \
		prm->playground->img, 0, TOP_GAP);
	return (0);
}
