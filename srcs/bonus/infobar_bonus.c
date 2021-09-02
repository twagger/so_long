/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infobar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:56:53 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 15:29:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long_bonus.h"

void	ft_img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_infobar(t_param *prm)
{
	int		x;
	int		y;
	t_data	infobar;

	infobar.img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, TOP_GAP);
	infobar.addr = mlx_get_data_addr(infobar.img, &infobar.bits_per_pixel, \
		&infobar.line_length, &infobar.endian);
	y = -1;
	while (++y < TOP_GAP)
	{
		x = -1;
		while (++x < (SSIZE * prm->map->cols))
			ft_img_pixel_put(&infobar, x, y, BG_COLOR);
	}
	mlx_put_image_to_window(prm->mlx, prm->win, infobar.img, 0, 0);
	if (prm->map->cols > 5)
		mlx_string_put(prm->mlx, prm->win, 8, 2, TXT_COLOR, "Total moves : ");
	else
		mlx_string_put(prm->mlx, prm->win, 8, 2, TXT_COLOR, "Tot : ");
}

int	ft_update_move_info(t_param *prm)
{
	ft_init_infobar(prm);
	if (prm->map->cols > 5)
		mlx_string_put(prm->mlx, prm->win, 145, 2, TXT_COLOR, \
			ft_itoa(prm->nb_moves));
	else
		mlx_string_put(prm->mlx, prm->win, 65, 2, TXT_COLOR, \
			ft_itoa(prm->nb_moves));
	return (0);
}
