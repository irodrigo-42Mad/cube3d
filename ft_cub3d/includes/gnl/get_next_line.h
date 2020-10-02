/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:54:29 by irodrigo          #+#    #+#             */
/*   Updated: 2020/09/23 11:33:22 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define L_EOF 		'\n'
# define FILE_DSC	4096

//char	*ft_strdup(const char *src);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strjoin(char const *s1, char const *s2);
//size_t	ft_strlen(const char *str);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_memfree(char **str_line);
int		get_next_line(int fd, char **line);

#endif
