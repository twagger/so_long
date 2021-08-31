/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:56:29 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 09:01:33 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_and_return(char **to_free, int to_return)
{
	if (to_free)
		free(*to_free);
	if (to_return)
		return (to_return);
	return (-1);
}

int	ft_exit_w_message(char *message, int fd, int code)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	return (code);
}
