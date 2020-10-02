/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:06:15 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/22 15:00:27 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include "./keys.h"
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./liberror/ft_error.h"
# include "./gnl/get_next_line.h"

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_game
{
	int			max_res_x;
	int			max_res_y;
	int			res_x;
	int			res_y;
	t_point		spr_pos;
}				t_game;

/*
**auxiliar libft functions
*/
char			*ft_right(const char *mystr, int len);

/*
**preopen check functions
*/
int				ft_check_args(int argc, char **argv);
int				ft_check_ext (char *ext);
int				ft_check_open_ok(char *ruta);
short			exists(char *fname);

/*
**read and validation functions
*/
int				ft_ckeck_myfile(int file_fd);

#endif
