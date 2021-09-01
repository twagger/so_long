/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/01 12:55:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# define ERROR -1
# define AUTHORIZED "01CEP"
# define WALL '1'
# define NBSPRITES 17
# define SPRITES "0001COEXPLU1U2U3R1R2R3D1D2D3L1L2L3"
# define UP 0
# define RIGHT 1
# define DOWN 2
# define LEFT 3

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
	int		nb_moves;
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
int			ft_exit_w_message(char *message, char *message2, int fd, int code);

/*
** Map
*/

int			ft_map_controler(int fd, int *rows);
int			ft_create_map(int fd, t_map *map, int rows);
void		ft_draw_map(t_map *map, void *mlx, void *win);
int			ft_free_map(t_map *map, int ret_code);

/*
** Loop
*/

int			ft_handle_close(void *param);
int			ft_handle_key(int key, void *param);

/*
** Sprites
*/

char		*ft_get_path(int c);
int			ft_init_imgs(t_map *map, void *mlx);

/*
** Actions
*/

int			ft_move(t_param *param, int move);
t_player	ft_get_player_pos(t_map *map);

#endif