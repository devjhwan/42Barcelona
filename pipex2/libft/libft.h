/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:33:17 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 14:58:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*Part 1*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);

/*Part 2*/
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(int count, ...);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*Bonus Part*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstpopfirst(t_list **list);

/*Personal libft*/
int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	*ft_realloc(void *p, size_t oldsize, size_t newsize);

/*ft_printf*/
# define MAX_INT_DIGIT 1000000000
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_flag
{
	unsigned char	f;
	int				width;
	int				precition;
	char			conversion;
}	t_flag;

# define ZERO 1
# define MINUS 2
# define PRECITION 4
# define PLUS 8
# define HASHTAG 16
# define SPACE 32

int		ft_printf(const char *str, ...);
int		ft_print_format(const char *str, int *i, va_list ap);
int		ft_print_conversion(t_flag *flag, va_list ap);

int		ft_print_char(t_flag *flag, char c);
int		ft_print_str(t_flag *flag, char *s);
int		ft_print_ptr(t_flag *flag, size_t p);
int		ft_print_dec(t_flag *flag, int d);
int		ft_print_udec(t_flag *flag, unsigned int u);
int		ft_print_hdecl(t_flag *flag, unsigned int hl);
int		ft_print_hdecu(t_flag *flag, unsigned int hu);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_base(size_t nb, char *base);
int		ft_putptr(size_t ptr);
int		ft_flush_buffer(char *buff, int len);
void	ft_setnbr_base(char *buff, size_t nb, char *base);
int		ft_nblen_base(size_t nb, size_t baselen);

/*get_next_line*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buff
{
	char			*b;
	ssize_t			curlen;
	ssize_t			maxlen;
	ssize_t			lasti;
	int				fd;
	struct s_buff	*next;
}	t_buff;

char	*get_next_line(int fd);

t_buff	*ft_setbuffer(t_buff **blist, int fd);
void	*ft_realloc(void *p, size_t oldsize, size_t newsize);
void	*ft_freebuffer(t_buff **blist, int fd);
#endif
