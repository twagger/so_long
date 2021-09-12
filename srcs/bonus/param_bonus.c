/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:42:20 by twagner           #+#    #+#             */
/*   Updated: 2021/09/12 09:56:28 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_count_items(t_map *map, char item)
{
	int	row;
	int	col;
	int	res;

	res = 0;
	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		while (++col < map->cols)
		{
			if (map->map[row][col] == item)
				++res;
		}
	}
	return (res);
}

int	ft_free_param(t_param *param, void *mlx, int ret_code)
{
	int	i;

	if (param->img)
	{
		i = -1;
		while (++i < NBSPRITES)
		{
			if (mlx)
				mlx_destroy_image(mlx, param->img[i]);
			else
				free(param->img[i]);
		}
		free(param->img);
	}
	if (param->playground)
		free(param->playground->addr);
	free(param->playground);
	if (param->move.img)
		free(param->move.img);
	free(param);
	return (ret_code);
}

char	*ft_get_path(int i)
{
	char	path[50];

	path[0] = '\0';
	ft_strlcat(path, "theme/", 50);
	ft_strlcat(path, THEME, 50);
	ft_strlcat(path, "/", 50);
	ft_strlcat(path, &SPRITES[i * 2], ft_strlen(path) + 3);
	ft_strlcat(path, ".xpm", 50);
	return (ft_strdup(path));
}

int	ft_init_imgs(t_param *param, void *mlx)
{
	int		i;
	int		w;
	int		h;
	char	*path;

	path = NULL;
	param->img = (void **)malloc(sizeof(param->img) * NBSPRITES);
	if (!param->img)
		return (ERROR);
	i = -1;
	while (++i < NBSPRITES)
	{
		path = ft_get_path(i);
		if (!path)
			return (ERROR);
		param->img[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
		path = NULL;
		if (!param->img[i])
			return (ERROR);
	}
	return (0);
}

int	ft_init_param(t_param **param, void *mlx, void *win, t_map *map)
{
	*param = (t_param *)malloc(sizeof(**param));
	if (!param)
		return (ERROR);
	(*param)->mlx = mlx;
	(*param)->win = win;
	(*param)->map = map;
	(*param)->curr_items = 0;
	(*param)->curr_moves = 0;
	(*param)->total_items = ft_count_items(map, 'C');
	(*param)->is_on_exit = 0;
	(*param)->frames = 0;
	(*param)->playground = ft_init_frame(*param);
	(*param)->move.nb_move = 0;
	(*param)->move.next_img = 0;
	(*param)->move.from_exit = 0;
	(*param)->move.to_exit = 0;
	(*param)->keyblock = 0;
	(*param)->move.img = (void **)malloc(sizeof(void *) * 3);
	if (!(*param)->playground || !(*param)->move.img)
		return (ERROR);
	if (ft_init_imgs(*param, mlx) == ERROR)
		return (ERROR);
	return (0);
}
