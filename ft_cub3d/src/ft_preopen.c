/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preopen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:17:28 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/23 09:00:33 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/gnl/get_next_line.h"

static int	ft_prn_error(char *tittle, char *msg, int err_n)
{
	write(2, tittle, ft_strlen(tittle));
	write(2, msg, ft_strlen(msg));
	return (err_n);
}

short		exists(char *fname)
{
	int fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (errno == ENOENT) ? -1 : -2;
	return (fd);
}

int			ft_check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (ft_prn_error(TIT_001, MSG_001, EXIT_FAILURE));
	else
	{
		if (strcmp(argv[0], "./Cub3D") != 0)
			return (ft_prn_error(TIT_002, MSG_002, EXIT_FAILURE));
		if (argc == 2)
			if (strcmp(argv[1], "--save") == 0)
				return (ft_prn_error(TIT_003, MSG_001, EXIT_FAILURE));
			else if (strcmp(ft_strtrim(ft_right(argv[1], 3), "\n"), "cub") != 0)
				return (ft_prn_error(TIT_004, MSG_003, EXIT_FAILURE));
		else
		{
			if (strcmp(argv[1], "--save") == 0)
			{
				if (strcmp(ft_strtrim(ft_right(argv[2], 3), "\n"), "cub") != 0)
					return (ft_prn_error(TIT_005, MSG_001, EXIT_FAILURE));
				else
					return (ft_prn_error(TIT_003, MSG_001, EXIT_FAILURE));
			}
			else
			{
				if (strcmp(ft_strtrim(ft_right(argv[1], 3), "\n"), "cub") != 0)
					printf("wrong map name");
				else if (strcmp(argv[2], "--save") != 0)
					printf("wrong save option");
			}
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int			ft_check_open_ok(char *ruta)
{
	int err_n;
	int fd;

	err_n = exists(ruta);
	if (err_n == -1)
	{
		printf("El archivo no existe\n");
		return (err_n);
	}
	if (err_n == -2)
	{
		printf("Ocurrió un error al abrir: %d (%s)\n", err_n, strerror(errno));
		return (err_n);
	}
	if (err_n > 0)
		fd = err_n;
	return (fd);
}

/*
**fd = open(ruta, O_RDONLY);
*/

int			ft_ckeck_myfile(int file_fd)
{
	int             r_code;
        char    *line;

        //ft_init_file_struct(f);
        while ((r_code = get_next_line(file_fd, &line)) >= 0)
        {
			printf("%s",line);
		}
	/*if (ft_check_resolution() != EXIT_SUCCESS)
		return EXIT_FAILURE;
	if (ft_check_textures(texture) != EXIT_SUCCESS)
		return EXIT_FAILURE;
	if (ft_check_colors(color_dat) != EXIT_SUCCESS)
		return EXIT_FAILURE;*/
	close(file_fd);
	return (EXIT_SUCCESS);
}
