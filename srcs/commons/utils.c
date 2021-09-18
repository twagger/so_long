/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:56:29 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 23:29:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

int	ft_getmove(int key)
{
	int	i;
	int	res;
	int	kb[4];

	res = 0;
	kb[0] = K_UP;
	kb[1] = K_RIGHT;
	kb[2] = K_DOWN;
	kb[3] = K_LEFT;
	i = -1;
	while (++i < 4)
	{
		if (key == kb[i])
			res = i;
	}
	return (res);
}

int	ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code)
{
	if (map)
		ft_free_map(map, 0);
	if (param)
		ft_free_param(param, mlx, 0);
	return (ret_code);
}

int	ft_free_and_return(char **to_free, int to_return)
{
	if (to_free)
		free(*to_free);
	if (to_return)
		return (to_return);
	return (-1);
}

int	ft_exit_w_message(char *message, char *message2, int fd, int code)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	if (message2)
	{
		ft_putstr_fd(message2, fd);
		ft_putchar_fd('\n', fd);
	}
	return (code);
}
