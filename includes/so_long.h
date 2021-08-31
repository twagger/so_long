/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 11:09:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# define ERROR -1
# define AUTHORIZED "01CEP"
# define WALL '1'

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}			t_map;

/*
** Commons
*/

int	ft_free_and_return(char **to_free, int to_return);
int	ft_exit_w_message(char *message, int fd, int code);

/*
** Map
*/

int	ft_map_controler(int fd, int *rows);
int	ft_map_creator(int fd, t_map *map, int rows);
int	ft_init_map(t_map *map, int rows);
int	ft_free_map(t_map *map, int ret_code);

/*
** Game
*/

int	ft_game_loop(t_map *map);

#endif