/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:12:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 14:05:49 by twagner          ###   ########.fr       */
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
# define AUTHORIZED "01CEPURDL"
# define MOBS "PURDL"
# define WALL '1'
# define NBSPRITES 29
# define SPRITES "0001COEXPLU1U2U3R1R2R3D1D2D3L1L2L3F1F2F3G1G2G3H1H2H3I1I2I3"
# define SSIZE 32
# define TOP_GAP 25
# define THEME "default"
# define BG_COLOR 0x009C9C15
# define TXT_COLOR 0x00FFFFFF
# define UP 0
# define RIGHT 1
# define DOWN 2
# define LEFT 3
# define NBMOVES 8

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

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_mob
{
	char			type;
	int				x;
	int				y;
	int				next_x;
	int				next_y;
	int				move;
	int				nb_move;
	int				next_img;
	int				from_exit;
	int				to_exit;
	int				from_coll;
	int				to_coll;
	struct s_mob	*next;
}			t_mob;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		**img;
	int			total_items;
	int			curr_items;
	int			curr_moves;
	int			is_on_exit;
	t_data		*playground;
	t_data		*infoscore;
	t_data		*infoend;
	int			frames;
	int			keyblock;
	int			endgame;
	t_mob		*mobs;
}				t_param;

/*
** Commons
*/

int		ft_free_and_return(char **to_free, int to_return);
int		ft_exit_w_message(char *message, char *message2, int fd, int code);
int		create_trgb(int t, int r, int g, int b);
int		ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code);
int		ft_init_param(t_param **param, void *mlx, void *win, t_map *map);
int		ft_free_param(t_param *param, void *mlx, int ret_code);

/*
** Map
*/

int		ft_map_controler(int fd, int *rows);
int		ft_create_map(int fd, t_map **map, int rows);
int		ft_free_map(t_map *map, int ret_code);

/*
** Hooks
*/

int		ft_handle_close(void *param);
int		ft_handle_key(int key, void *param);
int		ft_render_next_frame(void *param);
int		ft_endgame(t_param *prm, char *message);

/*
** Images
*/

char	*ft_get_path(int c);
int		ft_init_imgs(t_param *param, void *mlx);
void	ft_draw_image(t_param *param, void *img, int x, int y);
int		ft_init_img(t_param *prm, t_data **img, int width, int height);
int		ft_clear_img(t_data *img, int width, int height);

/*
** Actions
*/

int		ft_mover(t_param *param, int move);
void	ft_do_move(t_param *param);
t_mob	ft_get_player_pos(t_map *map);
int		ft_get_pos(int curr, int next, int n);
char	ft_get_next_tile(int x, int y, int move, t_map *map);

void	ft_get_next_position(t_mob *m, int move, char next_tile);
void	ft_register_move(char type, t_param *prm, int move);
void	ft_move_mobs(t_param *prm);

void	ft_mobsclear(t_mob **lst);
t_mob	*ft_moblast(t_mob *lst);
void	ft_mobsadd_back(t_mob **lst, t_mob *new);
void	ft_update_map_array(t_mob *m, t_param *prm);
int		ft_create_mobs(t_map *map, t_param *prm);
void	ft_register_ennemy_moves(t_param *prm);

/*
** Info score
*/

int		ft_init_infoscore(t_param *param);
int		ft_update_infoscore(t_param *prm);

/*
** Drawing
*/

t_data	*ft_init_frame(t_param *prm);
void	ft_free_frame(t_data *frame);
void	ft_img_pixel_put(t_data *data, int x, int y, int pix);
void	ft_put_object(void *img, t_data *frame, int x, int y);
void	ft_put_sprite(void *img, t_data *frame, int x, int y);
void	ft_draw_playground(t_map *map, t_param *param);

/*
** Patrol
*/

int		ft_move_patrol(t_param *prm);

#endif