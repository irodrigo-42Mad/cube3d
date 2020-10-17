/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:07:39 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/16 14:04:35 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

t_game_draw     *ft_init_struct(t_game_draw *game, t_win *my_game)
{
    my_game = (t_win *) malloc (1 * sizeof(t_win));
	game = (t_game_draw *) malloc(1 * sizeof(t_game_draw *));
	return (game);
}

t_game_draw     *ft_set_init_val(t_game_draw *game)
{
	// si estamos en linux miramos resoluciones, sino por defecto
	game->res_w = SCREENWIDTH;
	game->res_h = SCREENHEIGHT;
	game = ft_set_init_draw(game);
	//game = ft_set_raycast(game);
	return (game);
}

t_game_draw		*ft_set_init_draw (t_game_draw *game)
{
	game->loop_ok = 1;
    game->pos.x = 22.0;
    game->pos.y = 11.5;
    game->dir.x = -1.0;
    game->dir.y = 0.0;
    game->ray.x = 0.0;
    game->ray.y = 0.66;
	return (game);
}

t_game_draw		*ft_set_raycast(t_game_draw *game)
{
	// inicializaremos las variables necesarias para el raycast
	write (1, "1", 1);
	return (game);
}
