# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/09/04 18:46:45 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRCDIR=source
OBJDIR=objs
SRCS=fdf_free.c fdf_key_hook.c fdf_mouse_hook.c fdf_map.c fdf_matrix.c \
	 fdf_quaternion.c fdf_quaternion2.c fdf_map2.c fdf_map3.c fdf_draw.c \
	 fdf_map4.c fdf_loop_hook.c fdf_reshape.c fdf_spherical_perspective.c \
	 fdf_draw2.c fdf_loop_hook2.c fdf_main.c fdf_loop_hook3.c \
	 fdf_check_error.c fdf_check_error2.c fdf_draw3.c fdf_color.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-Iinclude -Ilibft -Iminilibx_macos -Iminilibx-linux
CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

EXTRA_FLAGS=-Lminilibx_macos -lmlx \
		   	-framework OpenGl -framework AppKit -lm
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a
EXTRA_FLAGS_LINUX=-Lminilibx-linux -lXext -lX11 -lm -lz
LIBRARIES_LINUX=libft/libft.a minilibx-linux/libmlx.a

all: $(OBJDIR) minilibx libf $(NAME)

$(NAME): $(OBJS) Makefile
ifeq ($(shell uname), Linux)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES_LINUX) \
		$(EXTRA_FLAGS_LINUX) $(INCLUDE) -o $@ 
else
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ $(OBJS) $(LIBRARIES)
endif
	echo "(FDF) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile $(LIBRARIES)
ifeq ($(shell uname), Linux)
	$(CC) $(CFLAGS) -Iinclude -Ilibft -Iminilibx-linux -O3 -c $< -o $@
else
	$(COMPILE.c) $@ $<
endif
	echo "(FDF) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

minilibx:
ifeq ($(shell uname), Linux)
	make -C minilibx-linux
else
	make -C minilibx_macos
endif

libf:
	make -C libft

clean:
	make -C libft fclean
	rm -rf $(OBJDIR)

fclean: clean
ifeq ($(shell uname), Linux)
	make -C minilibx-linux clean
else
	make -C minilibx_macos clean
endif
	rm -f $(NAME)

re: fclean all

debug: all
	./fdf $(shell ls -d test_maps/* | sed -n 5p)

-include $(DEPS)

.PHONY: all clean fclean re minilibx libf debug
.SILENT:
