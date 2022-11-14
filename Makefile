# **************************************************************************** #
#	                                                                          #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 19:14:37 by pgros             #+#    #+#              #
#    Updated: 2022/10/20 15:25:06 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR= src/
OBJDIR = obj/
INCDIR = include/
LIB42DIR = $(INCDIR)lib42/
MLXDIR = $(INCDIR)minilibx-linux/

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

SRCS =	main.c \
		parsing/parse.c \
		parsing/parse_bis.c \
		parsing/set_colors.c \
		utils/map.c \
		utils/lstmap.c \
		utils/geometry.c \
		utils/color.c
		# utils/strtab.c

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

INCS_FILES = fdf.h \
				geometry.h \
				map.h \
				color.h

INCS = $(addprefix ./include/, $(INCS_FILES))

LIB42 = $(LIB42DIR)lib42.a
LIBMLX = $(MLXDIR)libmlx.a

I_FLAG = -I./$(INCDIR) -I./$(LIB42DIR) -I./$(MLXDIR)
MLX_FLAGS = -L./$(MLXDIR) -lmlx
LIB42_FLAGS = -L./$(LIB42DIR) -l42
LIBS_FLAGS = $(LIB42_FLAGS) $(MLX_FLAGS) -lXext -lX11 -lm

CC = cc 
C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p ${@D}
	@$(CC) $(CFLAGS) $(I_FLAG) -c $< -o $@

$(NAME): $(OBJS) $(INCS) $(LIB42) $(LIBMLX)
	@echo -n "Compiling FdF"
	@$(CC) $(CFLAGS) $(I_FLAG) $(OBJS) $(LIBS_FLAGS) -o $@
	@echo ${GREEN}"\t\tOK"${RESET}
		
$(LIBMLX) :
	@echo -n "Compiling minilibx"
	@make -s -C${MLXDIR} > /dev/null 2>&1
	@echo ${GREEN}"\t\tOK"${RESET}

$(LIB42) :
	@echo -n "Compiling lib42"
	@make -s -C${LIB42DIR} > /dev/null 2>&1
	@echo ${GREEN}"\t\tOK"${RESET}


clean:
	rm -rf $(OBJDIR)
	@make clean -s -C$(MLXDIR)
	@make clean -s -C$(LIB42DIR) > /dev/null 2>&1

fclean: clean
	rm -f $(NAME)
	@make fclean -C$(LIB42DIR) > /dev/null 2>&1

re: fclean all
	make all
	
.PHONY: all clean fclean re 