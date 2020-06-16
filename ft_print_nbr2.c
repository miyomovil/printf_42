/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:17:53 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:28:35 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	long_int_min_spc(t_env *ptr)
{
	write(1, "2147483648", 10);
	ptr->wr = ptr->wr + 10;
}

void	ft_print_nbr2(long nb, char c, t_env *ptr)
{
	if (ptr->prec == 0 && ptr->min == 1 && ptr->width != -1)
		wr_inc_pr_spc(ptr);
	else
	{
		if (nb < 0)
		{
			nb = -(nb);
			wr_inc_pr_min(ptr);
		}
		if (nb > 9)
		{
			ft_print_nbr((nb) / 10, ptr);
			ft_print_nbr((nb) % 10, ptr);
		}
		else
		{
			c = (nb) + '0';
			write(1, &c, 1);
			(ptr->wr)++;
		}
	}
}
