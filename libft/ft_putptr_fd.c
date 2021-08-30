/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:00:25 by twagner           #+#    #+#             */
/*   Updated: 2021/07/23 14:54:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_size_in_base(unsigned long nb, int bsize)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= bsize;
		size++;
	}
	return (size);
}

static char	*ft_ultoa_base(unsigned long nb, char *base, int bsize)
{
	int		i;
	int		tab_size;
	char	*number;

	tab_size = ft_size_in_base(nb, bsize);
	number = (char *)malloc(sizeof(*number) * (tab_size + 3));
	if (!number)
		return (NULL);
	number[0] = '0';
	number[1] = 'x';
	if (nb == 0)
		number[2] = '0';
	i = 1;
	while (nb != 0)
	{
		number[tab_size + 2 - i] = base[nb % bsize];
		nb /= bsize;
		++i;
	}
	number[tab_size + 2] = '\0';
	return (number);
}

void	ft_putptr_fd(void *ptr, int fd)
{
	char	*res;

	res = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef", 16);
	ft_putstr_fd(res, fd);
	if (res)
		free(res);
}
