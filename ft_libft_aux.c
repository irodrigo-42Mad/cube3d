/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:41:14 by irodrigo          #+#    #+#             */
/*   Updated: 2020/10/11 23:48:39 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

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
	result = ft_calloc(len, sizeof(char));
	while (act_char < len)
	{
		result[act_char] = mystr[pos_ini + act_char];
		act_char++;
	}
	return (result);
}
