/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:00:05 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 12:03:26 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wr_error(char *tittle, char *message, int err_n)
{
	write(2, tittle, ft_strlen(tittle));
	write(2, message, ft_strlen(message));
	return (err_n);
}

/*
**close_game(p);
*/
