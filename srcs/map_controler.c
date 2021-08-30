/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:47:55 by twagner           #+#    #+#             */
/*   Updated: 2021/08/30 17:14:12 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_line_a_wall(char *line)
{
	int	i;

	i = -1;
	if (line)
	{
		while (line[++i])
		{
			if (line[i] != WALL)
				return (0);
		}
	}
	return (1);
}

int	ft_is_line_ok(char *line, size_t size)
{
	int	i;

	if (ft_strlen(line) != size)
		return (0);
	if (ft_is_line_a_wall(line))
		return (2);
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

int	ft_is_yet_char(const char *possibles, int c, int check)
{
	int	sum;

	sum = 0;
	while (*possibles)
	{
		if (check - c == *possibles || check - c == sum)
			return (1);
		sum += (int)*possibles;
		++possibles;
	}
	if (check - c == sum)
		return (1);
	return (0);
}

void	ft_mandatory_char_check(char *line, int *check)
{
	if (ft_strchr(line, 'E') - line >= 0 && !ft_is_yet_char("PC", 'E', *check))
		*check += 'E';
	if (ft_strchr(line, 'P') - line >= 0 && !ft_is_yet_char("EC", 'P', *check))
		*check += 'P';
	if (ft_strchr(line, 'C') - line >= 0 && !ft_is_yet_char("EP", 'C', *check))
		*check += 'C';
}

int	ft_map_controler(int fd)
{
	int		ret;
	int		char_check;
	size_t	line_size;
	char	*line;

	line = NULL;
	char_check = 0;
	ret = get_next_line(fd, &line);
	line_size = ft_strlen(line);
	while (ret > 0)
	{
		if (!ft_is_line_ok(line, line_size))
		{
			free(line);
			return (ERROR);
		}
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
