/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 08:47:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int key, void *param)
{
	if (key == K_QUIT)
	{
		mlx_loop_end(((t_param *)param)->mlx);
		ft_free_mem(((t_param *)param)->map, (t_param *)param, \
			((t_param *)param)->mlx, 0);
	}
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		if (ft_mover(param, ft_getmove(key)) == 1)
		{
			mlx_loop_end(((t_param *)param)->mlx);
			ft_free_mem(((t_param *)param)->map, (t_param *)param, \
				((t_param *)param)->mlx, 0);
		}
	}
	ft_putstr_fd("Current move count : ", 1);
	ft_putnbr_fd(((t_param *)param)->curr_moves, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	ft_handle_close(void *param)
{
	ft_free_mem(((t_param *)param)->map, (t_param *)param, \
		((t_param *)param)->mlx, 0);
	return (0);
}

int	ft_render_next_frame(void *param)
{
	mlx_put_image_to_window(((t_param *)param)->mlx, ((t_param *)param)->win, \
		((t_param *)param)->playground->img, 0, TOP_GAP);
	return (0);
}
