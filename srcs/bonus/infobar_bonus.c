/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infobar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:56:53 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 23:40:25 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_init_infobar(t_param *prm)
{
	int		x;
	int		y;
	t_data	infobar;

	infobar.img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, TOP_GAP);
	if (infobar.img == NULL)
		return (ERROR);
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
	return (0);
}

int	ft_update_move_info(t_param *prm)
{
	if (ft_init_infobar(prm) == ERROR)
		return (ERROR);
	if (prm->map->cols > 5)
		mlx_string_put(prm->mlx, prm->win, 145, 2, TXT_COLOR, \
			ft_itoa(prm->nb_moves));
	else
		mlx_string_put(prm->mlx, prm->win, 65, 2, TXT_COLOR, \
			ft_itoa(prm->nb_moves));
	return (0);
}
