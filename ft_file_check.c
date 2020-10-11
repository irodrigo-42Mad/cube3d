/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:00:50 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 23:41:35 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	ft_ckeck_myfile(int fd_game)
{
	char	*line;
	int		result;

	result = 1;
	while (result == 1)
	{
		result = get_next_line(fd_game, &line);
		printf("%s\n\n", line);
		//check_info(); // faltan cosas
		free(line);
	}
	close(fd_game);
	return (0);
}
