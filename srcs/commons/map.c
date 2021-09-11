/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:23:43 by twagner           #+#    #+#             */
/*   Updated: 2021/09/11 13:32:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long.h"
#endif

int	ft_free_map(t_map *map, int ret_code)
{
	int	i;

	if (map)
	{
		if (map->map)
		{
			i = -1;
			while (++i < map->rows)
				free(map->map[i]);
		}
		free(map);
	}
	return (ret_code);
}

int	ft_init_map(t_map *map, int rows)
{
	int	i;

	map->map = (char **)malloc(sizeof(map->map) * rows);
	if (!map->map)
		return (ERROR);
	i = -1;
	while (++i < rows)
		map->map[i] = NULL;
	map->rows = rows;
	map->cols = 0;
	return (0);
}

void	ft_add_line(t_map *map, char *line)
{
	int	i;

	i = -1;
	while (++i < map->rows)
	{
		if (!map->map[i])
		{
			map->map[i] = line;
			break ;
		}
	}
	if (map->cols == 0)
		map->cols = ft_strlen(line);
}

int	ft_create_map(int fd, t_map **map, int rows)
{
	int		ret;
	char	*line;

	*map = (t_map *)malloc(sizeof(**map));
	if (!(*map))
		return (ERROR);
	if (ft_init_map(*map, rows) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		ft_add_line(*map, line);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	if (ret == ERROR)
		return (ft_free_map(*map, ERROR));
	else
		ft_add_line(*map, line);
	return (0);
}
