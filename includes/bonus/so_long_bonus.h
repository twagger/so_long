/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/11 15:32:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifdef LINUX
#  include "mlx.h"
# else
#  include <mlx.h>
# endif
# include "libft.h"
# define ERROR -1
# define AUTHORIZED "01CEP"
# define WALL '1'
# define NBSPRITES 17
# define SPRITES "0001COEXPLU1U2U3R1R2R3D1D2D3L1L2L3"
# define SSIZE 32
# define TOP_GAP 25
# define THEME "default"
# define BG_COLOR 0x009C9C15
# define TXT_COLOR 0x00FFFFFF
# define UP 0
# define RIGHT 1
# define DOWN 2
# define LEFT 3

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_move
{
	void	**img;
	int		nb_move;
	int		x;
	int		y;
	int		next_x;
	int		next_y;
}			t_move;

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
	int		frames;
	t_move	move;
}			t_param;

typedef struct s_sprite
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
}		t_sprite;

/*
** Commons
*/

int			ft_free_and_return(char **to_free, int to_return);
int			ft_exit_w_message(char *message, char *message2, int fd, int code);
int			create_trgb(int t, int r, int g, int b);
int			ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code);
int			ft_init_param(t_param **param, void *mlx, void *win, t_map *map);
int			ft_free_param(t_param *param, void *mlx, int ret_code);

/*
** Map
*/

int			ft_map_controler(int fd, int *rows);
int			ft_create_map(int fd, t_map **map, int rows);
int			ft_free_map(t_map *map, int ret_code);

/*
** Hooks
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
** Actions
*/

int			ft_mover(t_param *param, int move);
t_sprite	ft_get_player_pos(t_map *map);

/*
** Info bar
*/

int			ft_init_infobar(t_param *param);
int			ft_update_move_info(t_param *prm);

/*
** Drawing
*/

t_data		*ft_init_frame(t_param *prm);
void		ft_img_pixel_put(t_data *data, int x, int y, int pix);
void		ft_put_object(void *img, t_data *frame, int x, int y);
void		ft_put_sprite(void *img, t_data *frame, int x, int y);
void		ft_draw_playground(t_map *map, t_param *param);

#endif