/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:40:11 by twagner           #+#    #+#             */
/*   Updated: 2021/09/13 10:54:06 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_endmessage(t_param *prm, char *message)
{
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 20, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2), TXT_COLOR, message);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 60, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE, TXT_COLOR, \
			"your score : ");
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE + 70, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE, TXT_COLOR, \
			ft_itoa(prm->curr_moves - 1));
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 80, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + 2 * SSIZE, TXT_COLOR, \
			"Press <ESC> to quit");
}

void	ft_put_small_endmessage(t_param *prm, char *message)
{
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 20, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2), TXT_COLOR, message);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 25, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE, TXT_COLOR, \
			"score: ");
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE + 40, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE, TXT_COLOR, \
			ft_itoa(prm->curr_moves - 1));
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - 29, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + 2 * SSIZE, TXT_COLOR, \
			">><ESC><<");
}

int	ft_init_infoend(t_param *prm)
{
	int		x;
	int		y;
	
	prm->infoend = (t_data *)malloc(sizeof(t_data));
	if (!prm->infoend)
		return (ERROR);
	prm->infoend->img = mlx_new_image(prm->mlx, \
		prm->map->cols * SSIZE, 3 * SSIZE);
	if (prm->infoend->img == NULL)
		return (ERROR);
	prm->infoend->addr = mlx_get_data_addr(prm->infoend->img, \
		&prm->infoend->bits_per_pixel, &prm->infoend->line_length, \
			&prm->infoend->endian);
	y = -1;
	while (++y < 3 * SSIZE)
	{
		x = -1;
		while (++x < (SSIZE * prm->map->cols))
			ft_img_pixel_put(prm->infoend, x, y, BG_COLOR);
	}
	return (0);
}

int	ft_endgame(t_param *prm, char *message)
{
	prm->keyblock = 1;
	if (ft_init_infoend(prm) == ERROR)
		return (ERROR);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->infoend->img, 0, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) - 4);
	if (prm->map->cols < 8)
		ft_put_small_endmessage(prm, message);
	else
		ft_put_endmessage(prm, message);
	return (0);
}
