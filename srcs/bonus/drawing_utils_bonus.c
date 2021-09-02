/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:18:42 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 17:20:25 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long_bonus.h"

void	ft_img_pixel_put(t_data *data, int x, int y, int pix)
{
	char	*dst;

	dst = data->addr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = pix;
}

void	ft_put_sprite(void *img, t_data *frame, int x, int y)
{
	int		total;
	int		init_x;
	int		pix;
	t_data	obj;

	obj.img = img;
	obj.addr = mlx_get_data_addr(obj.img, &obj.bits_per_pixel, \
		&obj.line_length, &obj.endian);
	total = 0;
	init_x = x;
	while (total < SSIZE * SSIZE * obj.bits_per_pixel / 8)
	{
		pix = *(unsigned int *)(obj.addr + total);
		ft_img_pixel_put(frame, x, y, pix);
		++x;
		if (total % (SSIZE * obj.bits_per_pixel / 8) == 0)
		{
			++y;
			x = init_x;
		}
		total += 4;
	}
}

int	ft_init_frame(t_param *prm)
{
	int		x;
	int		y;
	t_data	frame;

	frame.img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, \
		prm->map->rows * SSIZE);
	if (frame.img == NULL)
		return (ERROR);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, \
		&frame.line_length, &frame.endian);
	y = -1;
	while (++y < prm->map->rows * SSIZE)
	{
		x = -1;
		while (++x < (SSIZE * prm->map->cols))
			ft_img_pixel_put(&frame, x, y, 0xFF000000);
	}
	mlx_put_image_to_window(prm->mlx, prm->win, frame.img, 0, TOP_GAP);
	ft_put_sprite(prm->map->img[4], &frame, 3 * SSIZE, 3 * SSIZE);
	mlx_put_image_to_window(prm->mlx, prm->win, frame.img, 0, TOP_GAP);
	return (0);
}
