/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:41:16 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 23:41:48 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_struct		*ft_modifiers(t_struct *temp)
{
	char *flag;

	flag = &temp->s_flag;
	if (*flag == 'c')
		ft_printc(temp);
	else if (*flag == 's' && ft_strcmp(temp->arg_flags, "l") == 0)
		ft_printsw(temp);
	else if (*flag == 's')
		ft_prints(temp);
	else if (*flag == 'S')
		ft_printsw(temp);
	else if (*flag == 'd' || *flag == 'D' || *flag == 'i')
		ft_printd(temp);
	else if (*flag == 'u')
		ft_printu(temp);
	else if (*flag == 'p')
		ft_printp(temp);
	else if (*flag == 'o')
		ft_printo(temp);
	else if (*flag == 'x' || *flag == 'X')
		ft_printx(temp);
	else
		ft_other_chars(temp);
	return (temp);
}
