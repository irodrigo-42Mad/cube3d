/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:30:04 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 22:45:57 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int fd_game;

	if (ft_check_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if ((fd_game = ft_check_open_ok(argv[1])) < 0)
		return (EXIT_FAILURE);
	if (ft_ckeck_myfile(fd_game) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_set_game(); // trabajando en este punto
	return (EXIT_SUCCESS);
}
