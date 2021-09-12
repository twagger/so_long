/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/12 11:42:00 by twagner          ###   ########.fr       */
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
	int	move_result;

	if (key == ESC)
	{
		ft_free_mem(((t_param *)param)->map, (t_param *)param, \
			((t_param *)param)->mlx, 0);
		exit(0);
	}
	if (key == W || key == S || key == A || key == D)
	{
		if (((t_param *)param)->keyblock == 0)
		{
			((t_param *)param)->endgame = ft_mover(param, KEYMAP[key] - 48);
			if (move_result == 1)
			{
				((t_param *)param)->endgame = 1;
				
			}
			if (move_result == 0)
				ft_update_move_info(param);
		}
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	ft_free_mem(((t_param *)param)->map, (t_param *)param, \
			((t_param *)param)->mlx, 0);
	exit(0);
	return (0);
}

int	ft_render_next_frame(void *param)
{
	if (((t_param *)param)->frames > 1000)
		((t_param *)param)->frames = 0;
	++(((t_param *)param)->frames);
	if (((t_param *)param)->frames % 3 == 0)
	{
		if (((t_param *)param)->move.nb_move > 0)
			ft_do_move((t_param *)param);
	}
	if (((t_param *)param)->endgame == 1)
	{
		// you lost, press esc to quit or space to retry
	}
	mlx_put_image_to_window(((t_param *)param)->mlx, ((t_param *)param)->win, \
		((t_param *)param)->playground->img, 0, TOP_GAP);
	return (0);
}
