/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_zer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:05 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:26:10 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_check_zer(const char *str, t_env *ptr, va_list args)
{
	ptr->cnt = 0;
	while (str[ptr->cnt] == '0' && ptr->min == 1)
		ptr->cnt++;
	while (str[ptr->cnt] == '0' && ptr->min != 1)
	{
		ptr->zer = 1;
		ptr->cnt++;
	}
}
