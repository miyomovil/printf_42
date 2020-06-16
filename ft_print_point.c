/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:02:07 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:50:17 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	wr_mem_st(t_env *ptr)
{
	write(1, "0x", 2);
	ptr->wr++;
	ptr->wr++;
}

void	ft_print_point(unsigned long nbr, t_env *ptr)
{
	wr_mem_st(ptr);
	ft_print_low_hex_nbr(nbr, ptr);
}

void	ft_print_low_ptr2(unsigned long nbr, t_env *ptr)
{
	if (ptr->prec == 0 && nbr == 0 &&
			(ptr->width == -1 || ptr->width == 2))
		wr_mem_st(ptr);
	else
	{
		if (ptr->width == 9 && ptr->prec == 2)
			wr_inc_pr_spc(ptr);
		if (ptr->width > 0 && ptr->prec == -1 && nbr != 0 &&
			ptr->flag_pw == -1)
		{
			if (ptr->width < ft_get_atr_length(nbr))
				ptr->flag_pw++;
			else
				wr_inc_pr_spc(ptr);
		}
		ft_print_ulmin_uzer(&nbr, ft_get_atr_length(nbr) + 2, ptr);
		if (ptr->prec == 0 && nbr == 0 && ptr->width != -1)
		{
			wr_inc_pr_spc(ptr);
			wr_mem_st(ptr);
		}
		else
			ft_print_point(nbr, ptr);
	}
}

void	ft_print_low_ptr(unsigned long int nbr, t_env *ptr)
{
	if (ptr->prec != -1 && ft_get_atr_length(nbr) < ptr->prec)
	{
		wr_mem_st(ptr);
		ft_print_ulprec(nbr, ptr);
	}
	else
	{
		if (ptr->min == 1 && ptr->prec != 0)
		{
			ft_print_point(nbr, ptr);
			ptr->flag_pm = 0;
			ft_print_ulmin_uzer(&nbr, ft_get_atr_length(nbr), ptr);
		}
		else
			ft_print_low_ptr2(nbr, ptr);
	}
}
