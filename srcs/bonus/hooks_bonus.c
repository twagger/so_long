/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 12:31:18 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long_bonus.h"
#define ESC 53
#define W 13
#define S 1
#define A 0
#define D 2
#define KEYMAP "321----------0"

int	ft_update_move_info(void *param)
{
	t_param *prm;
	void	*info_img;

	prm = (t_param *)param;
	if (prm->info_img)
		mlx_destroy_image(prm->mlx, prm->info_img);
	info_img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, \
		prm->map->rows * SSIZE);
	mlx_string_put(prm->mlx, info_img, 100, 0, create_trgb(0, 255, 255, 255), \
			"1");
	return (0);
}

int	ft_handle_key(int key, void *param)
{
	int	move_result;

	if (key == ESC)
		exit(0);
	if (key == W || key == S || key == A || key == D)
	{
		move_result = ft_move(param, KEYMAP[key] - 48);
		if (move_result == 1)
			exit(0);
		if (move_result == 0)
			ft_update_move_info(param);
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	ft_free_map(((t_param *)param)->map, ERROR, NULL);
	exit(0);
	return (0);
}
