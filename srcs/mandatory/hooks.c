/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:01:18 by twagner           #+#    #+#             */
/*   Updated: 2021/09/11 14:30:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define ESC 53
#define W 13
#define S 1
#define A 0
#define D 2
#define KEYMAP "321----------0"

int	ft_handle_key(int key, void *param)
{
	if (key == ESC)
	{
		ft_free_mem(((t_param *)param)->map, (t_param *)param, \
			((t_param *)param)->mlx, 0);
		exit(0);
	}
	if (key == W || key == S || key == A || key == D)
	{
		if (ft_mover(param, KEYMAP[key] - 48) == 1)
		{
			ft_free_mem(((t_param *)param)->map, (t_param *)param, \
				((t_param *)param)->mlx, 0);
			exit(0);
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
	exit(0);
	return (0);
}
