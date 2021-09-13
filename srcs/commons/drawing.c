/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:18:42 by twagner           #+#    #+#             */
/*   Updated: 2021/09/13 10:58:07 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

void	ft_img_pixel_put(t_data *data, int x, int y, int pix)
{
	char	*dst;

	if ((unsigned int)pix != 0xFF000000)
	{
		dst = data->addr + \
			(y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = pix;
	}
}

void	ft_put_sprite(void *img, t_data *frame, int x, int y)
{
	int		total;
	int		init_x;
	int		init_y;
	int		pix;
	t_data	obj;

	obj.img = img;
	obj.addr = mlx_get_data_addr(obj.img, &obj.bits_per_pixel, \
		&obj.line_length, &obj.endian);
	total = 0;
	init_x = x;
	init_y = y;
	while (y < init_y + SSIZE)
	{
		pix = *(unsigned int *)(obj.addr + total);
		ft_img_pixel_put(frame, x, y, pix);
		if (++x == init_x + SSIZE)
		{
			++y;
			x = init_x;
		}
		total += 4;
	}
}

void	ft_free_frame(t_data *frame)
{
	if (frame)
	{
		if (frame->addr)
			free(frame->addr);
		free(frame);
	}
}

t_data	*ft_init_frame(t_param *prm)
{
	int		x;
	int		y;
	t_data	*frame;

	frame = (t_data *)malloc(sizeof(*frame));
	if (!frame)
		return (NULL);
	frame->img = mlx_new_image(prm->mlx, prm->map->cols * SSIZE, \
		prm->map->rows * SSIZE);
	if (frame->img == NULL)
		return (NULL);
	frame->addr = mlx_get_data_addr(frame->img, \
		&(frame->bits_per_pixel), &(frame->line_length), \
		&(frame->endian));
	y = -1;
	while (++y < prm->map->rows * SSIZE)
	{
		x = -1;
		while (++x < (SSIZE * prm->map->cols))
			ft_img_pixel_put(frame, x, y, 0xFF000000);
	}
	return (frame);
}

void	ft_draw_playground(t_map *map, t_param *param)
{
	int	col;
	int	row;
	int	img_i;
	int	curr_x;
	int	curr_y;

	curr_y = 0;
	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		curr_x = 0;
		while (++col < map->cols)
		{
			img_i = ft_strchr_index(AUTHORIZED, map->map[row][col], 0);
			ft_put_sprite(param->img[0], param->playground, \
				curr_x, curr_y);
			ft_put_sprite(param->img[img_i], param->playground, \
					curr_x, curr_y);
			curr_x += SSIZE;
		}
		curr_y += SSIZE;
	}
}
