/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:35:32 by twagner           #+#    #+#             */
/*   Updated: 2021/09/10 10:50:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

void	ft_draw_image(t_param *param, void *img, int x, int y)
{
	mlx_put_image_to_window(param->mlx, param->win, \
			img, x * SSIZE, (y * SSIZE) + TOP_GAP);
}
