# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 10:39:12 by irodrigo          #+#    #+#              #
#    Updated: 2020/09/23 11:45:09 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ APP name ======================================
NAME	:=	get_next_line.a		# change if necesary

# ========================== COMPILER OPTS ====================================
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
RM	:=	rm -f
LIBFT	:=	../libft/libft.h

# ============================ Source files ====================================

SRC=get_next_line.c

OBJ=$(SRC:.c=.o)

$(NAME): ./get_next_line.h
	@$(CC) $(CFLAGS) -c $(SRC) -L $(LIBFT) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "[===================]"
	@echo "|     succes !      |"
	@echo "|  get_next_line.a  |"
	@echo "|   was created     |"
	@echo "[===================]"

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJBONUS)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean: clean
	@$(RM) $(NAME) $(OBJBONUS)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "| get_next_line.a |"
	@echo "|   was removed   |"
	@echo "[=================]"

re: fclean all

.PHONY: clean fclean
