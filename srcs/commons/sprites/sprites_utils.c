/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:35:32 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 09:57:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

char	*ft_get_path(int i)
{
	char	path[23];

	path[0] = '\0';
	ft_strlcat(path, "tileset/", 23);
	ft_strlcat(path, THEME, 23);
	ft_strlcat(path, "/", 23);
	ft_strlcat(path, &SPRITES[i * 2], 19);
	ft_strlcat(path, ".xpm", 23);
	return (ft_strdup(path));
}

int	ft_init_imgs(t_map *map, void *mlx)
{
	int		i;
	int		w;
	int		h;
	char	*path;

	path = NULL;
	map->img = (void **)malloc(sizeof(map->img) * NBSPRITES);
	if (!map->img)
		return (ERROR);
	i = -1;
	while (++i < NBSPRITES)
	{
		path = ft_get_path(i);
		if (!path)
			return (ERROR);
		map->img[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
		path = NULL;
		if (!map->img[i])
			return (ERROR);
	}
	return (0);
}
