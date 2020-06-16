/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:03:54 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:54:28 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <limits.h>

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
