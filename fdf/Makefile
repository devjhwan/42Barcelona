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
SRCS=fdf.c free_mlx.c fdf_key_hook.c fdf_mouse_hook.c parse_fdf.c matrix.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-Iinclude -Ilibft -Iminilibx_macos -Iminilibx-linux
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

EXTRA_FLAGS=-Lminilibx_macos -lmlx \
		   	-framework OpenGl -framework AppKit -lm
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a
EXTRA_FLAGS_LINUX=-Lminilibx-linux -lXext -lX11 -lm -lz
LIBRARIES_LINUX=libft/libft.a minilibx-linux/libmlx.a

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	make -C libft
ifeq ($(shell uname), Linux)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES_LINUX) \
		$(EXTRA_FLAGS_LINUX) $(INCLUDE) -o $@ 
else
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ $(OBJS) $(LIBRARIES)
endif
	echo "(FDF) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile
ifeq ($(shell uname), Linux)
	$(CC) $(CFLAGS) -Iinclude -Ilibft -Iminilibx-linux -O3 -c $< -o $@
else
	make -C minilibx_macos
	$(COMPILE.c) $@ $<
endif
	echo "(FDF) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	make -C libft fclean
	rm -rf $(OBJDIR)

fclean: clean
	make -C minilibx_macos clean
	make -C minilibx-linux clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
