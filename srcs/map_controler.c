/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:47:55 by twagner           #+#    #+#             */
/*   Updated: 2021/08/30 15:15:14 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_line_a_wall(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != WALL)
			return (0);
	}
	return (1);
}

int	ft_is_line_ok(char *line, int ret, int first)
{
	int i;

	if (ret == 0 || first == 1)
		return (ft_is_line_a_wall(line));
	else
	{
		i = -1;
		while (line[++i])
		{
			if (i == 0 && line[i] != WALL)
				return (0);
			if (ft_strchr_index(AUTHORIZED, line[i], 0) == ERROR)
				return (0);
		}
		if (i < 3)
			return (0);
		if (line[i - 1] != WALL)
			return (0);
		return (1);
	}
}

int	ft_is_char_present(const char *possibles, int c, int check)
{
	while (*possibles)
	{
		if (check - c == *possibles)
			return (1);
		++possibles;
	}
	if (check - c == *possibles)
		return (1);
	return (0);
}

void	ft_mandatory_char_check(char *line, int *check)
{
	if (ft_strchr(line, 'E') >= 0 && !ft_is_char_present("PC", 'E', *check))
		*check += 'E';
	if (ft_strchr(line, 'P') >= 0 && !ft_is_char_present("EC", 'P', *check))
		*check += 'P';
	if (ft_strchr(line, 'C') >= 0 && !ft_is_char_present("EP", 'C', *check))
		*check += 'C';
}

int	ft_map_controler(int fd)
{
	int		ret;
	int		char_check;
	size_t	line_size;
	int		first;
	char	*line;

	first = 1;
	line = NULL;
	char_check = 0;
	ret = get_next_line(fd, &line);
	line_size = ft_strlen(line);
	while (ret >= 0)
	{
		if (!ft_is_line_ok(line, ret, first) || ft_strlen(line) != line_size)
		{
			free(line);
			return (ERROR);
		}
		first = 0;
		ft_mandatory_char_check(line, &char_check);
		free(line);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (ret == -1 || char_check != ('E' + 'P' + 'C'))
		return (ERROR);
	return (0);
}