/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:29:40 by twagner           #+#    #+#             */
/*   Updated: 2021/07/24 16:12:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (!ptr)
	{
		new = (char *)malloc(sizeof(*new) * size);
		if (!new)
			return (ptr);
		return (new);
	}
	if (size == 0 && ptr)
	{
		new = (char *)malloc(sizeof(*new));
		if (!new)
			return (ptr);
		new[0] = 0;
		return (new);
	}
	new = (char *)malloc(sizeof(*new) * size);
	if (!new)
		return (ptr);
	new = ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}
