/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:18:42 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 23:40:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_put_movable(t_param *prm)
{
	int	col;
	int	row;
	int	img_i;
	int	curr_x;
	int	curr_y;

	curr_y = TOP_GAP;
	row = -1;
	while (++row < prm->map->rows)
	{
		col = -1;
		curr_x = 0;
		while (++col < prm->map->cols)
		{
			img_i = ft_strchr_index(AUTHORIZED, prm->map->map[row][col], 0);
			if (ft_strchr(MOVABLE, prm->map->map[row][col]))
				ft_put_sprite(prm->map->img[img_i], prm->frame, curr_x * SSIZE, curr_y * SSIZE);
			curr_x += SSIZE;
		}
		curr_y += SSIZE;
	}
}

int	ft_init_frame(t_param *prm)
{
	int		x;
	int		y;

	prm->frame = (t_data *)malloc(sizeof(*(prm->frame)));
	if (!prm->frame)
		return (ERROR);
	prm->frame->img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, \
		prm->map->rows * SSIZE);
	if (prm->frame->img == NULL)
	{
		free(prm->frame);
		return (ERROR);
	}
	prm->frame->addr = mlx_get_data_addr(prm->frame->img, \
		&(prm->frame->bits_per_pixel), &(prm->frame->line_length), \
		&(prm->frame->endian));
	y = -1;
	while (++y < prm->map->rows * SSIZE)
	{
		x = -1;
		while (++x < (SSIZE * prm->map->cols))
			ft_img_pixel_put(prm->frame, x, y, 0xFF000000);
	}
	mlx_put_image_to_window(prm->mlx, prm->win, prm->frame->img, 0, TOP_GAP);
	ft_put_movable(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->frame->img, 0, TOP_GAP);
	return (0);
}
