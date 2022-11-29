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
		parsing/check_filepath.c \
		display/display.c \
		display/display_map.c \
		display/handles.c \
		display/handles_rot.c \
		display/handles_zoom.c \
		display/handles_translate.c \
		display/segment.c \
		display/transforms.c \
		geometry/geometry.c \
		geometry/matrices.c \
		geometry/fill_matrices.c \
		utils/map.c \
		utils/lstmap.c \
		utils/color.c

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

INCS_FILES = fdf.h \
				geometry.h \
				map.h \
				color.h \
				display.h

INCS = $(addprefix include/, $(INCS_FILES))

LIB42 = $(LIB42DIR)lib42.a
LIBMLX = $(MLXDIR)libmlx.a

I_FLAG = -I./$(INCDIR) -I./$(LIB42DIR) -I./$(MLXDIR)
MLX_FLAGS = -L./$(MLXDIR) -lmlx
LIB42_FLAGS = -L./$(LIB42DIR) -l42
LIBS_FLAGS = $(LIB42_FLAGS) $(MLX_FLAGS) -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -g

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCS)
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

re: fclean
	make all

debug: $(LIB42) $(LIBMLX)
	$(CC) $(CFLAGS) $(I_FLAG) $(addprefix $(SRCDIR), $(SRCS)) $(LIBS_FLAGS) -o fdf_debug
	
.PHONY: all clean fclean re 