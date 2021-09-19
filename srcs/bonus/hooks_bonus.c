/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 09:34:33 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_handle_key(int key, void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	if (key == K_QUIT)
		ft_free_mem(prm->map, prm, prm->mlx, 0);
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		if (prm->keyblock == 0)
			ft_register_move('P', param, ft_getmove(key));
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	ft_free_mem(prm->map, prm, prm->mlx, 0);
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

void	ft_register_ennemy_moves(t_param *prm)
{
	ft_register_move('U', prm, ft_getmove(K_UP));
	ft_register_move('L', prm, ft_getmove(K_LEFT));
	ft_register_move('D', prm, ft_getmove(K_DOWN));
	ft_register_move('R', prm, ft_getmove(K_RIGHT));
}

int	ft_render_next_frame(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	if (prm->frames > 1000)
		prm->frames = 0;
	++(prm->frames);
	ft_unfreeze_player(prm);
	if (prm->endgame == ENDSCREEN)
		return (0);
	if (prm->frames % SPEED == 0)
	{
		ft_move_mobs(prm);
		ft_register_ennemy_moves(prm);
	}
	if (prm->endgame > 0)
	{
		if (ft_endgame(prm, prm->endgame) == ERROR)
			ft_free_mem(prm->map, prm, prm->mlx, ERROR);
		return (0);
	}
	if (ft_update_infoscore(prm) == ERROR)
		ft_free_mem(prm->map, prm, prm->mlx, ERROR);
	mlx_put_image_to_window(prm->mlx, prm->win, \
		prm->playground->img, 0, TOP_GAP);
	return (0);
}
