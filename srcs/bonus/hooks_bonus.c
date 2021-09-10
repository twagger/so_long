/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/10 10:41:36 by twagner          ###   ########.fr       */
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
		ft_free_map(((t_param *)param)->map, 0, ((t_param *)param)->mlx);
		exit(0);
	}
	if (key == W || key == S || key == A || key == D)
	{
		move_result = ft_move(param, KEYMAP[key] - 48);
		if (move_result == 1)
		{
			ft_free_map(((t_param *)param)->map, 0, ((t_param *)param)->mlx);
			exit(0);
		}
		if (move_result == 0)
			ft_update_move_info(param);
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	ft_free_map(((t_param *)param)->map, 0, NULL);
	exit(0);
	return (0);
}
