/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:40:11 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 23:17:03 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_put_endmessage(t_param *prm, char *message)
{
	char	*score;

	score = ft_itoa(prm->curr_moves);
	if (!score)
		return (ERROR);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		EN_LEFT1, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + TOP, TXT_COLOR, message);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		EN_LEFT2, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE + TOP, TXT_COLOR, \
			"your score : ");
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE + \
		EN_LEFT3, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE + TOP, \
			TXT_COLOR, score);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		EN_LEFT4, \
		(prm->map->rows / 2) * SSIZE - \
		(SSIZE / 2) + 2 * SSIZE + TOP, TXT_COLOR, "Press <ESC> to quit");
	free(score);
	return (0);
}

int	ft_put_small_endmessage(t_param *prm, char *message)
{
	char	*score;

	score = ft_itoa(prm->curr_moves);
	if (!score)
		return (ERROR);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		S_EN_LEFT1, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + TOP, TXT_COLOR, message);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		S_EN_LEFT2, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE + TOP, TXT_COLOR, \
			"score: ");
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE + \
		S_EN_LEFT3, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) + SSIZE + TOP, TXT_COLOR, \
			score);
	mlx_string_put(prm->mlx, prm->win, (prm->map->cols / 2) * SSIZE - \
		S_EN_LEFT4, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) \
		 + 2 * SSIZE + TOP, TXT_COLOR, ">><ESC><<");
	free(score);
	return (0);
}

int	ft_endgame(t_param *prm, int mess_num)
{
	prm->keyblock = 1;
	prm->endgame = ENDSCREEN;
	if (ft_update_infoscore(prm) == ERROR)
		ft_free_mem(prm->map, prm, prm->mlx, ERROR);
	if (ft_init_img(prm, &prm->infoend, prm->map->cols * SSIZE, 3 * SSIZE) \
		== ERROR)
		return (ERROR);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->infoend->img, 0, \
		(prm->map->rows / 2) * SSIZE - (SSIZE / 2) - 4);
	if (prm->map->cols < 8 && mess_num == 1)
		return (ft_put_small_endmessage(prm, "You win !"));
	if (prm->map->cols < 8 && mess_num == 2)
		return (ft_put_small_endmessage(prm, "You lose !"));
	if (prm->map->cols > 7 && mess_num == 1)
		return (ft_put_endmessage(prm, "You win !"));
	if (prm->map->cols > 7 && mess_num == 2)
		return (ft_put_endmessage(prm, "You lose !"));
	return (0);
}
