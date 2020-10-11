/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_prime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:07:22 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 10:21:44 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_win_mlxexit(void *param)
{
	t_win *game;

	game = (t_win *)param;
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	return (0);
}

int	ft_key_mlxpress(int keycode, void *param)
{
	t_win *game;

	game = (t_win *)param;
	if (keycode == KEY_ESC)
		ft_win_mlxexit(game);
	return (0);
}
