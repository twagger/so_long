/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:40:11 by twagner           #+#    #+#             */
/*   Updated: 2021/09/13 15:36:25 by twagner          ###   ########.fr       */
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
		(prm->map->rows / 2) * SSIZE - \
		(SSIZE / 2) + 2 * SSIZE, TXT_COLOR, "Press <ESC> to quit");
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

int	ft_endgame(t_param *prm, char *message)
{
	prm->keyblock = 1;
	if (ft_init_img(prm, &prm->infoend, prm->map->cols * SSIZE, 3 * SSIZE) \
		== ERROR)
		return (ERROR);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->infoend->img, 0, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) - 4);
	if (prm->map->cols < 8)
		ft_put_small_endmessage(prm, message);
	else
		ft_put_endmessage(prm, message);
	return (0);
}
