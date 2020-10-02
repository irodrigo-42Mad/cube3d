# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 11:45:19 by user42            #+#    #+#              #
#    Updated: 2020/09/23 11:23:03 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======================== APP name change it ================================
APP			:=       Cub3D
NAME_BONUS		:=       Cub3D_Bonus

# ====================== initial config options ==============================
CC			:=	gcc
CCPLUS			:=	g++
FLAGS                   :=	-c -Wall -Wextra -Werror
CCFLAGS			:=	$(FLAGS)
IMG                     :=	cub3d.bmp
INCLUDES		:=	includes
OTHER_INC		:=	
SRC			:=	src
BONUS			:=	bonus
OBJ			:=	obj

# ========================== other libraries =================================
LIBFT			:=	$(INCLUDES)/libft
GNL			:=	$(INCLUDES)/gnl
PRINTF                  :=      $(INCLUDES)/printf
RAYCAST			:=	$(INCLUDES)/raycast
MINILIBX		:=	$(INCLUDES)/minilibx
LIBERROR		:=	$(INCLUDES)/liberror

# ========================== debuging options ================================
ifdef debug
	CFLAGS += -g -pedantic
	CCFLAGS += -g -pedantic
else
	CFLAGS += -O3
	CCFLAGS += -O3
endif

# =========================== linker process =================================

$(APP):	#$(DIRS)
	@make -C $(LIBFT)
	@make -C $(GNL)
	@make -C $(MINILIBX)
	@make -C $(LIBERROR)
#	@make -C $(PRINTF)
#	$(CC) $(SRC_DIR)*.c $(READ_DIR)ft_*.c $(RAYCAST_DIR)ft_*.c -lftprintf -L $(PRINTF_DIR)   -L$(MLX_DIR) $(MLX_DIR)libmlx.a -lm -lmlx -lXext -lX11 -o  $(NAME)
	$(CC) $(SRC)/*.c -L $(LIBFT)/ft_*.o -L $(GNL)/get_next_line*.o -L $(LIBERROR)/ft*.o -L $(MINILIBX) $(MINILIBX)/libmlx.a -lm -lmlx -lXext -lX11   -o $(APP)
	@echo "Done."

all: $(APP)

clean:
	@make -C $(PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "Cleaning Cub3d..."

fclean: clean
	@make -C $(MLX_DIR) clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(READ_DIR)*.o
	@rm -f $(RAYCAST_DIR)*.o
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(IMG)
	@echo "Cleaning Cub3d..."

bonus: $(NAME_BONUS)

bre: fclean bonus

PHONY: clean fcleam









