/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:17:02 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/16 14:34:43 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include "key.h"
# include "colors.h"
# include "ft_error.h"
# include "libft/libft.h"

/*
** las dos constantes screenwidth y screenheight se calcularán en una
** funcion de linux de la minilibx, pero de momento, las dejo en manual
** por el momento
*/

/*
**Conditional compilation inclusions
*/
# ifdef __linux__
#  include "../minilibx_linux/mlx.h"
#  define SCREENWIDTH 1024
#  define SCREENHEIGHT 768
# elif defined __APPLE_
#  include <mlx.h>
#  define SCREENWIDTH 1024
#  define SCREENHEIGHT 768
# endif

# define SCREENWIDTH 1024
# define SCREENHEIGHT 768
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define BUFFER_SIZE 1

# define FILE_DSC 4096
# define L_EOF '\n'

/*
**Data structs for game control
**=============================
**
**window controler and resolution
*/
typedef struct	s_win
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_win;

typedef struct  s_resol{
	int			w;
	int			h;
}				t_resol;

/*
**structs of setting control points
**=================================
**
**struct s_ipoint controls integer x/y positions
**struct s_fpoint controls double x/y positions
*/
typedef struct	s_ipoint{
		int			x;
		int			y;
}					t_ipoint;

typedef struct	s_fpoint{
		double		x;
		double		y;
}					t_fpoint;

/*
**other image and game structs
**============================
**
**configuration of image data
*/

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

/*
**control map file data
**=====================
**
**control file structure
*/

typedef struct	s_gm_sprite{
	t_resol		texres;
	t_fpoint	sprite;
	t_fpoint	transform;
	t_fpoint	displace;
	t_fpoint	act_pos;
	t_fpoint	ini_pos;
	t_ipoint	texture;
}				t_gm_sprite;

typedef struct	s_texture{
	char		*txt_path;
	int			**txt_data;
}				t_texture;

typedef struct	s_color{
	int			gamma;
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_file_head{
	int			sp_pos;
	t_resol		my_res;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;

	char		*sprite;
	t_color		*ceil;
	t_color		*floor;
}				t_file_head;

typedef struct	s_map
{
	t_file_head	info;
	short		**map;
}				t_map;


static int		s_wordmap[MAPWIDTH][MAPHEIGHT] =
{
	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
	{4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
	{4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
	{4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
	{4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
	{4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
	{6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
	{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
	{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}
};

static int		t_buffer[SCREENWIDTH][SCREENHEIGHT];

typedef struct	s_game_draw{
	int			res_h;
	int			res_w;

	int			loop_ok;
	int			hit;
	int			mside;
	double		camerax;

	t_fpoint	pos;
	t_fpoint	dir;
	t_fpoint	ray;
	t_fpoint	side;
	t_fpoint	delta_dt;

	t_ipoint	map;
	t_ipoint	step;

	t_gm_sprite	my_sprites[];
	// ojo, aqui faltan cosas.
}				t_game_draw;

int				exists(char *fname);
int				ft_check_args(int argc, char **argv);
int				ft_check_open_ok(char *ruta);
int				ft_ckeck_myfile(int	fd_game);

t_game_draw		*ft_init_struct(t_game_draw *game, t_win *my_win);
t_game_draw		*ft_set_init_val(t_game_draw *game);
t_game_draw		*ft_set_init_draw (t_game_draw *game);
t_win			*ft_set_game(t_win *my_game, t_game_draw *game);
//t_game_draw		*ft_set_game(t_game_draw *game);
t_game_draw		*ft_set_raycast(t_game_draw *game);

int				wr_error(char *tittle, char *message, int err_n);

int				ft_key_mlxpress(int keycode, void *param);
int				ft_key_mlxrelease(int keycode, void *param);
int				ft_win_mlxexit(void *param);

int				get_next_line(int fd, char **line);
void			ft_memfree(char **str_line);

char			*ft_right(const char *mystr, int len);
#endif
