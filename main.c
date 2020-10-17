/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:30:04 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/16 23:42:04 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close(int keycode, t_win *vars)
{
    mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	free (vars->mlx_ptr);
	exit (0);
}

int	main(int argc, char **argv)
{
	int			fd_game;
	t_win		*my_game;
	t_game_draw	*game;

	if (ft_check_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if ((fd_game = ft_check_open_ok(argv[1])) < 0)
		return (EXIT_FAILURE);
	if (ft_ckeck_myfile(fd_game) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
    if ((my_game = (t_win *) malloc(sizeof(t_win *))) != NULL)

    my_game->mlx_ptr = mlx_init();
    my_game->mlx_win = mlx_new_window(my_game->mlx_ptr, 1080, 720, "poseso Hello world!");
    mlx_hook(my_game->mlx_win, 17, 1L<<17, ft_close, my_game);
    mlx_loop(my_game->mlx_ptr);
 


	//game = ft_init_struct(game, my_game);
	//game = ft_set_init_val(game); //todo a 0
	
	//printf("x float %f y float %f\n",game->pos.x, game->pos.y);
	//printf("x float %f y float %f\n",game->dir.x, game->dir.y);
	//printf("x float %f y float %f",game->ray.x, game->    ray.y);
//	if ((my_game->mlx_ptr = mlx_init()) == NULL)
//		return (EXIT_FAILURE);
//	printf("llego aqui");
//	if ((my_game->mlx_win = mlx_new_window (
//		my_game->mlx_ptr, 800,
//		600, "Raycaster")) == NULL)
//			return (EXIT_FAILURE);

	/*mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
	while(game->loop_ok == 1)
	{*/
//		mlx_hook(my_game->mlx_win, 2, 1L<<0, ft_win_mlxexit, my_game->mlx_ptr);
//		mlx_loop(my_game->mlx_ptr);
		/*printf("Llego aqui");
	}*/
//	mlx_loop(my_game->mlx_ptr);
	//if ((my_game = ft_set_game (my_game, game)) == NULL)
	// error de creacion de juego
	
	//free (my_game);
	//free (game);
	
	return (EXIT_SUCCESS);
}
