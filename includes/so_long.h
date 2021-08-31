/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/08/31 17:14:53 by twagner          ###   ########.fr       */
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
	int		total_items;
	void	**img;
}			t_map;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		nb_items;
}			t_param;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

/*
** Commons
*/

int			ft_free_and_return(char **to_free, int to_return);
int			ft_exit_w_message(char *message, int fd, int code);

/*
** Map
*/

int			ft_map_controler(int fd, int *rows);
int			ft_map_creator(int fd, t_map *map, int rows);
int			ft_init_map(t_map *map, int rows);
int			ft_free_map(t_map *map, int ret_code);

/*
** Game
*/

int			ft_game_loop(t_map *map);
char		*ft_get_path(int c);
int			ft_init_imgs(t_map *map, void *mlx);

/*
** Actions
*/

int			move_up(t_param *param);
t_player	ft_get_player_pos(t_map *map);

#endif