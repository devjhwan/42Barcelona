# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/08/29 15:05:28 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
OBJDIR=objs
SRCS=ft_abs.c              ft_max.c              ft_putnbr_fd.c			\
	 ft_atoi.c             ft_memchr.c           ft_putstr_fd.c			\
	 ft_bzero.c            ft_memcmp.c           ft_realloc.c			\
	 ft_calloc.c           ft_memcpy.c           ft_setnbr_base.c		\
	 ft_flush_buffer.c     ft_memmove.c          ft_split.c				\
	 ft_isalnum.c          ft_memset.c           ft_strchr.c			\
	 ft_isalpha.c          ft_min.c              ft_strdup.c			\
	 ft_isascii.c          ft_nblen_base.c       ft_striteri.c			\
	 ft_isdigit.c          ft_print_char.c       ft_strjoin.c			\
	 ft_isprint.c          ft_print_conversion.c ft_strlcat.c			\
	 ft_itoa.c             ft_print_dec.c        ft_strlcpy.c			\
	 ft_lstadd_back.c      ft_print_format.c     ft_strlen.c			\
	 ft_lstadd_front.c     ft_print_hdecl.c      ft_strmapi.c			\
	 ft_lstclear.c         ft_print_hdecu.c      ft_strncmp.c			\
	 ft_lstdelone.c        ft_print_ptr.c        ft_strnstr.c			\
	 ft_lstiter.c          ft_print_str.c        ft_strrchr.c			\
	 ft_lstlast.c          ft_print_udec.c       ft_strtrim.c			\
	 ft_lstmap.c           ft_printf.c           ft_substr.c			\
	 ft_lstnew.c           ft_putchar.c          ft_tolower.c			\
	 ft_lstsize.c          ft_putchar_fd.c       ft_toupper.c			\
	 ft_lstpopfirst.c	   ft_strcmp.c			 get_next_line.c		\
	 get_next_line_utils.c ft_atoi_base.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
AR=ar rcs
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
COMPILE.c=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	$(AR) $@ $(OBJS)
	echo "(LIBFT) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(COMPILE.c) $@ $<
	echo "(LIBFT) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
