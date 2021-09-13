/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:48:08 by twagner           #+#    #+#             */
/*   Updated: 2021/09/13 15:23:56 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_patrol(t_param *prm)
{
	int	col;
	int	row;

	row = -1;
	while (++row < prm->map->rows)
	{
		col = -1;
		while (++col < prm->map->cols)
		{
			// si je suis sur un patrol
			// get position
			// get next tile
				// si next tile == 1 > 
					// get 
		}
	}
	return (0);
}
