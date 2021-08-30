/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:29:23 by twagner           #+#    #+#             */
/*   Updated: 2021/07/24 16:12:42 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_buffer_until_n(char **bufline, int fd)
{
	char	*buf;
	int		linelen;
	int		ret;

	buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ERROR);
	while (!ft_strchr(*bufline, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
		{
			free(buf);
			return (ret);
		}
		buf[ret] = '\0';
		linelen = (ft_strchr(*bufline, 0) - *bufline) + ret + 1;
		*bufline = ft_realloc(*bufline, linelen);
		ft_strlcat(*bufline, buf, linelen);
	}
	free(buf);
	return (STD_LINE);
}

static int	ft_update_bufline(char **bufline)
{
	char	*tofree;
	int		nl_index;

	tofree = *bufline;
	nl_index = ft_strchr(*bufline, '\n') - *bufline;
	*bufline = ft_substr(*bufline, nl_index + 1, \
		(ft_strchr(*bufline, 0) - *bufline) - (nl_index + 1));
	if (!*bufline)
	{
		*bufline = tofree;
		return (ERROR);
	}
	free(tofree);
	return (0);
}

static int	ft_return_line(char **line, char **bufline, int	status)
{
	int		nl_index;

	if (status == ERROR)
		return (ERROR);
	if (status == LAST_LINE)
	{
		*line = ft_substr(*bufline, 0, ft_strchr(*bufline, 0) - *bufline);
		if (!*line)
			return (ERROR);
		return (LAST_LINE);
	}
	else
	{
		nl_index = ft_strchr(*bufline, '\n') - *bufline;
		*line = ft_substr(*bufline, 0, nl_index);
		if (!*line)
			return (ERROR);
		if (ft_update_bufline(bufline) == ERROR)
			return (ERROR);
		return (STD_LINE);
	}
}

static int	ft_init_bufline(char **bufline)
{
	if (!*bufline)
	{
		*bufline = (char *)malloc(sizeof(**bufline) * (BUFFER_SIZE + 1));
		if (!*bufline)
			return (ERROR);
		*bufline[0] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*bufline = NULL;
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (ft_init_bufline(&bufline) == ERROR)
		return (ERROR);
	result = ft_fill_buffer_until_n(&bufline, fd);
	if (ft_return_line(line, &bufline, result) == ERROR)
	{
		free(bufline);
		bufline = NULL;
		return (ERROR);
	}
	else
	{	
		if (result == LAST_LINE)
		{
			free(bufline);
			bufline = NULL;
		}
		return (result);
	}
}
