/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:14:12 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/22 14:50:20 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "../libft/libft.h"

int	prn_fmt_err(char *tittle, char *msg, int err_n)
{
	write(2, tittle, ft_strlen(tittle));
	write(2, msg, ft_strlen(msg));
	return (err_n);
}
