/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:58:17 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:25:55 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_check_prec(const char *str, t_env *ptr, va_list args)
{
	if (str[ptr->cnt] == '.')
	{
		ptr->cnt++;
		if (str[ptr->cnt] == '*')
		{
			ptr->prec = va_arg(args, int);
			ptr->cnt++;
		}
		else
		{
			if (ft_isalpha(str[ptr->cnt]))
				ptr->prec = 0;
			else
				ptr->prec = ft_get_atr_nbr(str, ptr);
		}
	}
}
