/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/02 13:42:04 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# define ERROR -1
# define AUTHORIZED "01CEP"
# define STATIC "01CEP"
# define WALL '1'
# define NBSPRITES 5
# define SPRITES "0001COEXPL"
# define SSIZE 32
# define THEME "default"
# define TOP_GAP 0
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
	int		is_on_exit;
}			t_param;

typedef struct s_player
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
}		t_player;

/*
** Commons
*/

int			ft_free_and_return(char **to_free, int to_return);
int			ft_exit_w_message(char *message, char *message2, int fd, int code);
int			create_trgb(int t, int r, int g, int b);

/*
** Map
*/

int			ft_map_controler(int fd, int *rows);
int			ft_create_map(int fd, t_map *map, int rows);
void		ft_draw_map(t_map *map, void *mlx, void *win);
int			ft_free_map(t_map *map, int ret_code, void *mlx);

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
void		ft_draw_sprite(t_param *param, void *img, int x, int y);

/*
** Actions
*/

int			ft_mover(t_param *param, int move);
t_player	ft_get_player_pos(t_map *map);

#endif