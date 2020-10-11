/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:52:15 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 23:44:14 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exists(char *fname)
{
	int fd;
	int errno;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (errno == ENOENT) ? -1 : -2;
	return (fd);
}

static int	ft_check_two(int argc, char **argv)
{
	if (argc == 2 && strcmp(ft_substr(argv[1], 0, 2), "--") == 0 &&
		strcmp(argv[1], "--save") != 0)
		return (wr_error(TIT_006, MSG_001, EXIT_FAILURE));
	if (argc == 2 && strcmp(argv[1], "--save") == 0)
		return (wr_error(TIT_003, MSG_001, EXIT_FAILURE));
	if (argc == 2 && strcmp(ft_right(ft_strtrim(argv[1], "\n"), 3), "cub") != 0)
		return (wr_error(TIT_004, MSG_003, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int			ft_check_args(int argc, char **argv)
{
	if (strcmp(argv[0], "./Cub3D") != 0)
		return (wr_error(TIT_002, MSG_002, EXIT_FAILURE));
	if (argc < 2 || argc > 3)
		return (wr_error(TIT_001, MSG_001, EXIT_FAILURE));
	if (argc == 2)
		return (ft_check_two(argc, argv));
	if (argc == 3 && strcmp(ft_substr(argv[1], 0, 2), "--") == 0 &&
		strcmp(argv[1], "--save") != 0 &&
		strcmp(ft_right(ft_strtrim(argv[2], "\n"), 3), "cub") != 0)
		return (wr_error(TIT_005, MSG_001, EXIT_FAILURE));
	if (argc == 3 && strcmp(ft_substr(argv[1], 0, 2), "--") == 0 &&
		strcmp(argv[1], "--save") != 0 &&
		strcmp(ft_right(ft_strtrim(argv[2], "\n"), 3), "cub") == 0)
		return (wr_error(TIT_007, MSG_001, EXIT_FAILURE));
	if (argc == 3 && strcmp(argv[1], "--save") == 0 &&
		strcmp(ft_right(ft_strtrim(argv[2], "\n"), 3), "cub") != 0)
		return (wr_error(TIT_008, MSG_001, EXIT_FAILURE));
	if (argc == 3 && strcmp(argv[1], "--save") == 0 &&
		strcmp(ft_right(ft_strtrim(argv[2], "\n"), 3), "cub") == 0)
		return (wr_error(TIT_009, MSG_001, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int			ft_check_open_ok(char *ruta)
{
	int err_n;
	int fd;

	err_n = exists(ruta);
	if (err_n == -1)
		return (wr_error(TIT_009, MSG_004, err_n));
	if (err_n == -2)
		return (wr_error(TIT_010, strerror(errno), err_n));
	if (err_n > 0)
		fd = err_n;
	return (fd);
}
