# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 14:43:00 by jjauzion          #+#    #+#              #
#    Updated: 2018/04/16 18:31:22 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB, MLXLIB

SRC_NAME1 = main.c \
			trace_line.c \
			twd_right_lines.c \
			twd_left_lines.c \
			ver_hor_lines.c \
			init_tab.c \
			free_tab.c \
			parser.c \
			print_tab.c \
			projection.c \
			display.c \
			center2camera.c \
			event_hook.c \
			print2screen.c \
			trace_grid.c \
			operation_3d.c \
			ft_rgb2tsv.c \
			ft_tsv2rgb.c \
			pixel_put.c \
			color_scale.c \
			init_param.c

SRC_NAME2 = 

SRC_PATH1 = src/

SRC_PATH2 = src/

OBJ_PATH1 = .obj/

LIB_PATH = libft/

LDLIBS = libftprintf.a

EXT_LIB = -L minilibx -lmlx \
		  -framework OpenGL -framework AppKit

INC_PATH1 = libft/

INC_PATH2 = includes/

INC_NAME1 = ft_printf.h

INC_NAME2 = header.h

NAME = fdf

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
	CFLAGS =
	DBFLAGS =
endif
ifeq ($(FLAG), debug)
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS =
endif

SRC = $(addprefix $(SRC_PATH1),$(SRC_NAME1)) \
	  $(addprefix $(SRC_PATH2),$(SRC_NAME2))

OBJ1 = $(addprefix $(OBJ_PATH1),$(SRC_NAME1:.c=.o))

OBJ2 = $(addprefix $(OBJ_PATH1),$(SRC_NAME2:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_NAME2)) \
	   $(addprefix $(INC_PATH1),$(INC_NAME1))

LDFLAGS = $(addprefix $(LIB_PATH),$(LDLIBS))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: LIB MLXLIB $(NAME)

$(NAME): $(LDFLAGS) $(OBJ1) $(OBJ2)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ1) $(OBJ2) -o $(NAME)

LIB:
	make -C libft

MLXLIB:
	make -C minilibx

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	make -C libft clean
	rm -f $(OBJ1) $(OBJ2)
	@rmdir $(OBJ_PATH1) 2> /dev/null || true

fclean: clean
	make -C libft fclean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)
	norminette $(LIB_PATH)
