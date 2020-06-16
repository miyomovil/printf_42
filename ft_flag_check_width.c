/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:58:44 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 10:26:35 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flag_check_width(const char *str, t_env *ptr, va_list args)
{
	if (str[ptr->cnt] == '*')
	{
		ptr->width = va_arg(args, int);
		if (ptr->width < 0)
		{
			ptr->width = -(ptr->width);
			ptr->min = 1;
			if (ptr->zer == 1)
				ptr->zer = -1;
		}
		ptr->cnt++;
	}
	else
	{
		ptr->width = ft_get_atr_nbr(str, ptr);
	}
}
