/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:01:46 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:27:42 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_opt(char opt, va_list list, t_env *ptr)
{
	if (ptr->prec != -1 && ptr->zer == 1)
		ptr->zer = -1;
	if (ptr->zer != -1 && ptr->min == 1)
		ptr->min = -1;
	if (opt == 'c')
		ft_print_char(list, ptr);
	if (opt == 's')
		ft_print_str(list, ptr);
	if (opt == 'd' || opt == 'i')
		ft_print_int(va_arg(list, int), ptr);
	if (opt == 'x')
		ft_print_low_hex(va_arg(list, unsigned int), ptr);
	if (opt == 'X')
		ft_print_up_hex(va_arg(list, unsigned int), ptr);
	if (opt == 'u')
		ft_print_uint(va_arg(list, unsigned int), ptr);
	if (opt == 'p')
		ft_print_low_ptr(va_arg(list, unsigned long), ptr);
	if (opt == '%')
		ft_print_perc(list, ptr);
}
