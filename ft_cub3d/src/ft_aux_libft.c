/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:38:50 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 09:14:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_right(const char *mystr, int len)
{
	size_t	pos_fin;
	size_t	pos_ini;
	int		act_char;
	char	*result;

	if (*mystr == '\0')
		return (0);
	pos_fin = ft_strlen(mystr);
	pos_ini = pos_fin - len;
	act_char = 0;
	result = ft_calloc(len, 1);
	while (act_char < len)
	{
		result[act_char] = mystr[pos_ini + act_char];
		act_char++;
	}
	return (result);
}
