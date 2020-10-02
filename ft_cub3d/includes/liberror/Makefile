# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 10:39:12 by irodrigo          #+#    #+#              #
#    Updated: 2020/09/22 14:56:37 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================ APP name ======================================
NAME	:=	ft_error.a		# change if necesary

# ========================== COMPILER OPTS ====================================
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
RM	:=	rm -f
LDFLAGS	:=	-L.
LDLIBS	:=	-lft
HDDIRS	:=	-I includes/

# ============================ Source files ====================================

SRC=ft_error.c

OBJ=$(SRC:.c=.o)

$(NAME): ./ft_error.h
	@$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "[===================]"
	@echo "|     succes !      |"
	@echo "|    ft_error.a     |"
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
	@echo "|    ft_error.a   |"
	@echo "|   was removed   |"
	@echo "[=================]"

re: fclean all

.PHONY: clean fclean
