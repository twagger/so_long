/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:10:29 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 17:32:04 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

char	*ft_get_path(int c)
{
	if (c == '0')
		return ("tileset/default/ground.xpm");
	if (c == '1')
		return ("tileset/default/bush.xpm");
	if (c == 'C')
		return ("tileset/default/coll.xpm");
	if (c == 'E')
		return ("tileset/default/exit.xpm");
	if (c == 'P')
		return ("tileset/default/player.xpm");
	return ("");
}

int	ft_init_imgs(t_map *map, void *mlx)
{
	int		w;
	int		h;

	map->img = (void **)malloc(sizeof(map->img) * 5);
	if (!map->img)
		return (ERROR);
	map->img[0] = mlx_xpm_file_to_image(mlx, ft_get_path('0'), &w, &h);
	map->img[1] = mlx_xpm_file_to_image(mlx, ft_get_path('1'), &w, &h);
	map->img[2] = mlx_xpm_file_to_image(mlx, ft_get_path('C'), &w, &h);
	map->img[3] = mlx_xpm_file_to_image(mlx, ft_get_path('E'), &w, &h);
	map->img[4] = mlx_xpm_file_to_image(mlx, ft_get_path('P'), &w, &h);
	if (!map->img[0] || !map->img[1] || !map->img[2] || !map->img[3] \
		|| !map->img[4])
		return (ERROR);
	return (0);
}
