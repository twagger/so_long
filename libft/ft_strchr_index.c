/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:16:10 by twagner           #+#    #+#             */
/*   Updated: 2021/07/26 10:16:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_index(const char *s, int c, int offset)
{
	int	i;

	i = -1;
	while (s[++i + offset])
	{
		if (s[i + offset] == (char)c)
			return (i + offset);
	}
	if (c == 0 && s)
		return (i + offset);
	return (-1);
}
