/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:27:56 by twagner           #+#    #+#             */
/*   Updated: 2021/09/01 17:17:15 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long_bonus.h"

void	ft_animate_move(t_player p, int dir, t_param *param)
{
	if (dir == RIGHT)
	{
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.x * 32, p.y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[8], p.next_x * 42, p.next_y * 42);

		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.x * 32, p.y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.next_x * 32, p.next_y * 32);
		
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[9], p.next_x * 52, p.next_y * 52);

		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.x * 32, p.y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.next_x * 32, p.next_y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[10], p.next_x * 32, p.next_y * 32);
		
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[0], p.next_x * 32, p.next_y * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
			param->map->img[9], p.next_x * 32, p.next_y * 32);
	}
}