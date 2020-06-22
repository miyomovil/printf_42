/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:57:33 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:25:47 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_check_min(const char *str, t_env *ptr, va_list args)
{
	while (str[ptr->cnt] == '-')
	{
		ptr->min = 1;
		ptr->cnt++;
	}
}
