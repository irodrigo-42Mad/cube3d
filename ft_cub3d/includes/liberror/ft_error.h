/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:34:54 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/23 07:54:11 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define TIT_001	"Argument incorrect\n"
# define TIT_002	"program name not correct\n"
# define TIT_003        "wrong argument order (1) --save\n"
# define TIT_004        "Map name is not valid\n"
# define TIT_005        "Wrong order and map name\n"
# define TIT_006        "\n"

# define MSG_001        "correct use: Cub3D map.cub [--save]\n"
# define MSG_002        "correct name must be Cub3D\n"
# define MSG_003        "the correct name ends in .cub\n"
# define MSG_004        "\n"
# define MSG_005        "\n"
# define MSG_006        "\n"
# define MSG_007        "\n"
# define MSG_008	"\n"
# define MSG_009        "\n"
# define MSG_010	"\n"
# define MSG_011        "\n"
# define MSG_012        "\n"
# define MSG_013        "\n"
# define MSG_014        "\n"
# define MSG_015        "\n"
# define MSG_016        "\n"

int	prn_fmt_err(char *tittle, char *msg, int err_n);

#endif
