/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:40:22 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/16 14:46:07 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win		*ft_set_game(t_win *my_game, t_game_draw *game)
{
	if ((my_game->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	//hasta aqui ok;
	/*if ((my_game->mlx_win = mlx_new_window (
		my_game->mlx_ptr, 800,
		600, "Raycaster")) == NULL)
		return (NULL);
	while(game->loop_ok == 1)
	{
		mlx_hook(my_game->mlx_win, 17, 0, ft_win_mlxexit,
			my_game->mlx_ptr);
		mlx_loop(my_game->mlx_ptr);
		printf("Llego aqui");
	}*/
	return (my_game);
}
