/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/19 21:38:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifdef LINUX
#  include "mlx.h"
# else
#  include <mlx.h>
# endif
# include "libft.h"
# define ERROR -1

/*
** GAME PARAMS
*/

# define NBSPRITES 5
# define SSIZE 32
# ifdef HALLOWEEN
#  define THEME "halloween"
# else
#  define THEME "default"
# endif
# define TOP_GAP 0

/*
** SPRITE BINDING
*/

# define WALL '1'
# define AUTHORIZED "01CEP"
# define SPRITES "0001COEXPL"

/*
** KEY BINDING
*/

# ifdef X11
#  define K_QUIT 65307
#  define K_UP 119
#  define K_DOWN 115
#  define K_LEFT 97
#  define K_RIGHT 100
# else
#  define K_QUIT 65307
#  define K_UP 13
#  define K_DOWN 1
#  define K_LEFT 0
#  define K_RIGHT 2
# endif

/*
** DATA STRUCTURES
*/

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	**img;
	int		total_items;
	int		curr_items;
	int		curr_moves;
	int		is_on_exit;
	t_data	*playground;
}			t_param;

typedef struct s_sprite
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
}		t_sprite;

/*
** FUNCTIONS
*/

/*
** Commons
*/

int			ft_free_and_return(char *to_free, int to_return);
int			ft_exit_w_message(char *message, char *message2, int fd, int code);
int			ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code);
int			ft_init_param(t_param **param, void *mlx, void *win, t_map *map);
int			ft_free_param(t_param *param, void *mlx, int ret_code);
int			ft_getmove(int key);

/*
** Map
*/

int			ft_map_controler(int fd, int *rows);
int			ft_create_map(int fd, t_map **map, int rows);
int			ft_free_map(t_map *map, int ret_code);

/*
** Handlers
*/

int			ft_handle_close(void *param);
int			ft_handle_key(int key, void *param);
int			ft_render_next_frame(void *param);

/*
** Images
*/

char		*ft_get_path(int c);
int			ft_init_imgs(t_param *param, void *mlx);
void		ft_draw_image(t_param *param, void *img, int x, int y);

/*
** Moves
*/

int			ft_mover(t_param *param, int move);
t_sprite	ft_get_player_pos(t_map *map);

/*
** Drawing
*/

t_data		*ft_init_frame(t_param *prm);
void		ft_img_pixel_put(t_data *data, int x, int y, int pix);
void		ft_put_object(void *img, t_data *frame, int x, int y);
void		ft_put_sprite(void *img, t_data *frame, int x, int y);
void		ft_draw_playground(t_map *map, t_param *param);

#endif
