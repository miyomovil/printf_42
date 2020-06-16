/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:34:06 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:51:49 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	t_env	ptr;
	va_list args;

	va_start(args, str);
	ft_init_flags(&ptr);
	ft_init_flags2(&ptr);
	while (str[ptr.i])
	{
		if (str[ptr.i] == '%' && str[ptr.i + 1])
		{
			ptr.i += ft_flag_switch(str + ptr.i + 1, &ptr, args);
			ft_init_flags(&ptr);
		}
		else if (str[ptr.i] != '%')
		{
			if (ptr.i > ft_strlen(str))
				return (ptr.wr);
			write(1, &str[ptr.i], 1);
			i_n_wr_inc(&ptr);
		}
		else
			ptr.i++;
		va_end(args);
	}
	return (ptr.wr);
}
