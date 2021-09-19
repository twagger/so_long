/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoscore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:56:53 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 23:13:24 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_infomessage(t_param *prm)
{
	if (prm->map->cols > 5)
		mlx_string_put(prm->mlx, prm->win, 8, TOP, TXT_COLOR, "Total moves : ");
	else
		mlx_string_put(prm->mlx, prm->win, 8, TOP, TXT_COLOR, "Tot : ");
}

int	ft_update_infoscore(t_param *prm)
{
	char	*mess;

	if (!prm->infoscore)
	{
		if (ft_init_img(prm, &prm->infoscore, prm->map->cols * SSIZE, \
			TOP_GAP) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ft_clear_img(prm->infoscore, prm->map->cols * SSIZE, TOP_GAP) \
			== ERROR)
			return (ERROR);
	}
	mlx_put_image_to_window(prm->mlx, prm->win, prm->infoscore->img, 0, 0);
	ft_put_infomessage(prm);
	mess = ft_itoa(prm->curr_moves);
	if (!mess)
		return (ERROR);
	if (prm->map->cols > 5)
		mlx_string_put(prm->mlx, prm->win, SC_LEFT, TOP, TXT_COLOR, mess);
	else
		mlx_string_put(prm->mlx, prm->win, S_SC_LEFT, TOP, TXT_COLOR, mess);
	free(mess);
	return (0);
}
