/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lacosa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:39:40 by user42            #+#    #+#             */
/*   Updated: 2020/09/21 13:22:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static short exists(char *fname)
{
  int fd=open(fname, O_RDONLY);
  if (fd<0)			/* error */
    return (errno==ENOENT)?-1:-2;
  /* Si no hemos salido ya, cerramos */
  close(fd);
  return 0;
}

static void     ft_bzero(void *s, size_t n)
{
        char    *aux;
        size_t  pos;

        aux = s;
        pos = 0;
        if (n != 0)
                while (pos < n)
                {
                        aux[pos] = '\0';
                        pos++;
                }
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (size * count));
	return (mem);
}

static size_t		ft_strlen(const char *str)
{
	size_t pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

static char *ft_right(const char *mystr, int len)
{
    size_t  pos_fin;
    size_t  pos_ini;
    int     act_char;
    char    *result;
    
	if (*mystr == '\0')
        return(0);

    pos_fin = ft_strlen(mystr);
    pos_ini = pos_fin - len;
    act_char = 0;
    result = ft_calloc(len,1);

    while (act_char < len)
    {
        result[act_char] = mystr[pos_ini + act_char];
        act_char ++;
    }
    return (result);
}

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*c_str;

	i = 0;
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

static char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}


static char	*ft_strtrim(const char *s, const char *set)
{
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	len = ft_strlen(s);
	while (len && ft_strchr(set, s[len]))
		len--;
	ret = ft_substr(s, 0, len + 1);
	return (ret);
}

static int ft_check_args(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
	{    
        printf ("Error en los argumentos\n");
    	return EXIT_FAILURE;
	}
    else
	{ 
        if (strcmp(argv[0],"./Cub3D") != 0)
		{ 
			printf("el programa no tiene el nombre correcto\n");
			return EXIT_FAILURE;
    	}
		if (argc == 2)
		{
			if (strcmp(argv [1],"--save") == 0)
			{			
				printf("wrong argument --save\n");
				return EXIT_FAILURE;
			}
			else if (strcmp(ft_strtrim(ft_right(argv[1], 3),"\n"),"cub") != 0)
			{
				printf("wrong map name\n");
				return EXIT_FAILURE;
			}
		}
        else
 		{	// esta parte del if lo mismo necesita tratarse por separado,
			// hay que comprobar con dos argumentos
            if (strcmp(argv [1],"--save") == 0)
			{
                if (strcmp(ft_strtrim(ft_right(argv[2], 3),"\n"),"cub") != 0)
                    printf("wrong order and map name");
                else
                    printf("wrong order");
			}
			else
			{
                if(strcmp(ft_strtrim(ft_right(argv[1], 3),"\n"),"cub") != 0)
                    printf("wrong map name");
                else if (strcmp(argv [2],"--save") != 0)
					printf("wrong save option");
			}
			return EXIT_FAILURE;
		 }
	}
	return EXIT_SUCCESS;
}

static int ft_check_ext (char *ext)
{

	return EXIT_SUCCESS;
}

static int ft_check_open_ok(char *ruta)
{
	int err_n;
	int fd;

	err_n = exists (ruta);
	if (err_n == -1)
	{
		printf("El archivo no existe\n");
		return err_n;
	}
	if (err_n == -2)
	{
		printf("Ocurrió un error al abrir: %d (%s)\n", err_n, strerror(errno));
		return err_n;
	}
	fd = open(ruta, O_RDONLY);
	return fd;
}

static int ft_ckeck_myfile(int file_fd)
{
	/*if (ft_check_resolution() != EXIT_SUCCESS)
		return EXIT_FAILURE;
	if (ft_check_textures(texture) != EXIT_SUCCESS)
		return EXIT_FAILURE;
	if (ft_check_colors(color_dat) != EXIT_SUCCESS)
		return EXIT_FAILURE;*/


	
	printf("%d",file_fd);
	close (file_fd);
	return EXIT_SUCCESS;
}

int main (int argc, char **argv)
{
  	int fd_game;
	
	if (ft_check_args(argc, argv)!=EXIT_SUCCESS)
		return EXIT_FAILURE;
	if ((fd_game = ft_check_open_ok(argv[1]))<0)
		return EXIT_FAILURE;
	if (ft_ckeck_myfile(fd_game)!= EXIT_SUCCESS)
		return EXIT_FAILURE;
	
	printf("Archivo abierto");
  	return EXIT_SUCCESS;
}
