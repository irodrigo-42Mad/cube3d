/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:23:47 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 10:40:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*static int	ft_win_exit(void *param)
{
	t_data *game;

	game = (data_t *)param;
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	return (0);
}

static int	ft_key_press(int keycode, void *param)
{
	data_t *game;

	game = (data_t *)param;
	if (keycode == KEY_ESC)
		ft_win_exit(game);
	return (0);
}
*/

int main (int argc, char **argv)
{
	t_data	data;
	int 	fd_game;

	if (ft_check_args(argc, argv)!=EXIT_SUCCESS)
		return EXIT_FAILURE;
	if ((fd_game = ft_check_open_ok(argv[1]))<0)
		return EXIT_FAILURE;
	if (ft_ckeck_myfile(fd_game)!= EXIT_SUCCESS)
		return EXIT_FAILURE;

	printf("Archivo abierto");
	return EXIT_SUCCESS;


/*

	if (argc < 2 )
	{
			write (2,"error", 6);
			exit(1);
	}

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 1024, 768, "game")) == NULL)
        return (EXIT_FAILURE);
    mlx_pixel_put(data.mlx_ptr, data.mlx_win, 512, 384, 0xffffff);
	//ft_mlx_line(pto, pto2, data);
    mlx_hook(data.mlx_win, 2, 1L, ft_key_press, data.mlx_ptr);
	//mlx_hook(game->window, 3, 2L, game_key_release, game);
    mlx_hook(data.mlx_win, 17, 1L << 17, ft_win_exit, data.mlx_ptr);
    mlx_loop(data.mlx_ptr);*/
    return (EXIT_SUCCESS);
}
