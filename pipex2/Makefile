# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/08/29 17:34:02 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex

SRCDIR=.
OBJDIR=objs
SRCS=pipex.c parse_input.c error_handler.c pipe_execution.c get_path.c \
	 errmsg.c parse_input2.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I. -I./libft
AR=ar rcs
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(FLAGS) -o $@ $(OBJS) libft/libft.a
	echo "(PIPEX) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile
	$(COMPILE.c) $@ $<
	echo "(PIPEX) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean: test_clean
	rm -rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

bonus: all

test: all
	echo "aaaaaa" > input.txt
	./pipex input.txt "tr a b" "tr b c" output.txt
	echo "input.txt > "
	cat input.txt
	echo "output.txt > "
	cat output.txt

test2: all
	./pipex here_doc END "tr a b" "tr b c" output.txt
	echo "output.txt > "
	cat output.txt

test_clean:
	rm -f *.txt

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT:
