/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:00:20 by twagner           #+#    #+#             */
/*   Updated: 2021/07/24 16:14:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	if (!dup)
		return (NULL);
	return (ft_strcpy(dup, s1));
}
