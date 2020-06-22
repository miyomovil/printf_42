/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:25 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:26:18 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag_switch(const char *str, t_env *ptr, va_list args)
{
	ft_flag_check_zer(str, ptr, args);
	ft_flag_check_min(str, ptr, args);
	ft_flag_check_width(str, ptr, args);
	ft_flag_check_prec(str, ptr, args);
	ft_print_opt(str[ptr->cnt], args, ptr);
	return (ptr->cnt + 2);
}
