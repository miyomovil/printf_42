/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:33:29 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 13:53:44 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 256

# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_printf
{
	int	cnt;
	int	i;
	int n;
	int	width;
	int	min;
	int prec;
	int zer;
	int wr;
	int pr_i;
	int flag_pw;
	int flag_pm;

}				t_env;

void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
			const char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnew(size_t size);
char			*ft_substr_1(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isspace(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_negsign(int c);
int				ft_possign(int c);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_wordcount(const char *s, char c);
size_t			ft_wordlen(const char *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_memdel(void **ap);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
void			*ft_clear_lst(t_list *l, t_list *last, void (*del)(void *));
int				get_next_line(int fd, char **line);
char			*strjoin_and_free(char *s1, char *s2);
int				find_index(const char *s, int c);
int				get_line(char **str, char **line, int i);
size_t			ft_strlen(const char *s);
int				ft_printf(const char *str, ...);
void			ft_print_char(va_list list, t_env *ptr);
void			ft_print_int(int nbr, t_env *ptr);
void			ft_print_min_zer(int *nbr, int len, t_env *ptr);
void			ft_print_prec(int nbr, t_env *ptr);
void			ft_print_str(va_list list, t_env *ptr);
void			ft_print_nbr(int nbr, t_env *ptr);
void			ft_print_ulprec2(unsigned long int nbr, t_env *ptr);
void			ft_print_ulprec(unsigned long int nbr, t_env *ptr);
void			ft_print_ulmin_uzer(unsigned long int *nbr,
					int len, t_env *ptr);
void			ft_print_low_hex_nbr(unsigned long int nbr, t_env *ptr);
void			ft_print_up_hex_nbr(unsigned long nbr, t_env *ptr);
void			ft_print_low_hex(unsigned long int nbr, t_env *ptr);
void			ft_print_up_hex(unsigned long nbr, t_env *ptr);
void			ft_print_uint(unsigned int nbr, t_env *ptr);
void			ft_print_point(unsigned long int nbr, t_env *ptr);
void			ft_print_low_ptr(unsigned long int nbr, t_env *ptr);
void			ft_print_opt(char opt, va_list list, t_env *ptr);
void			ft_print_prec(int nbr, t_env *ptr);
void			ft_init_flags(t_env *ptr);
void			ft_init_flags2(t_env *ptr);
int				ft_print_bl_spac(int len, t_env *ptr);
int				ft_get_spa(char *str, t_env *ptr);
void			long_int_min_spc(t_env *ptr);
int				ft_flag_switch(const char *str, t_env *ptr, va_list args);
void			ft_flag_check_width(const char *str, t_env *ptr, va_list args);
void			ft_flag_check_prec(const char *str, t_env *ptr, va_list args);
void			ft_flag_check_min(const char *str, t_env *ptr, va_list args);
void			ft_flag_check_zer(const char *str, t_env *ptr, va_list args);
int				ft_get_atr_nbr(const char *str, t_env *ptr);
void			ft_print_nbr2(long nb, char c, t_env *ptr);
int				ft_get_atr_length(long int nbr);
void			wr_inc_pr_spc(t_env *ptr);
void			wr_inc_pr_min(t_env *ptr);
void			wr_inc_pr_zer(t_env *ptr);
void			i_n_wr_inc(t_env *ptr);
void			wr_mem_st(t_env *ptr);
void			wr_inc_pr_str(char *str, t_env *ptr);
void			ft_print_perc(va_list list, t_env *ptr);

#endif
