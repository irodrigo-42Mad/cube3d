/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:17:11 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/11 14:23:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_str;

	c_str = (char *)s;
	while (*c_str)
	{
		if (*c_str == c)
			return (c_str);
		c_str++;
	}
	if (*c_str == '\0' && c == '\0')
		return (c_str);
	return (NULL);
}
