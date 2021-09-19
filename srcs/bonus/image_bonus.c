/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:30:51 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 09:28:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_init_img(t_param *prm, t_data **img, int width, int height)
{
	int		x;
	int		y;
	t_data	*i;

	if (!img)
		return (ERROR);
	*img = (t_data *)malloc(sizeof(t_data));
	if (!*img)
		return (ERROR);
	i = *img;
	i->img = mlx_new_image(prm->mlx, width, height);
	if (i->img == NULL)
		return (ERROR);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_len, &i->endian);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_img_pixel_put(*img, x, y, BG_COLOR);
	}
	return (0);
}

int	ft_clear_img(t_data *img, int width, int height)
{
	int		x;
	int		y;

	if (!img)
		return (ERROR);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_img_pixel_put(img, x, y, BG_COLOR);
	}
	return (0);
}
