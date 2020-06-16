/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_low_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:01:17 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 10:26:19 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_ulprec2(unsigned long int nbr, t_env *ptr)
{
	while (ptr->pr_i < ptr->prec - ft_get_atr_length(nbr))
	{
		write(1, "0", 1);
		ptr->pr_i++;
		(ptr->wr)++;
	}
	if (ptr->width < ptr->prec && ptr->width != -1)
		wr_inc_pr_zer(ptr);
	ft_print_low_hex_nbr(nbr, ptr);
	while (ptr->width > ptr->wr)
	{
		wr_inc_pr_spc(ptr);
		ptr->pr_i++;
	}
}

void	ft_print_ulprec(unsigned long int nbr, t_env *ptr)
{
	ptr->pr_i = 0;
	if ((ptr->pr_i < (ptr->width - ptr->prec) && ptr->min != 1) && nbr < 0)
		ptr->pr_i++;
	while (ptr->pr_i < (ptr->width - ptr->prec) && ptr->min != 1)
	{
		wr_inc_pr_spc(ptr);
		ptr->pr_i++;
	}
	ptr->pr_i = 0;
	if (ptr->pr_i < ptr->prec - ft_get_atr_length(nbr) && nbr < 0)
	{
		nbr = -nbr;
		wr_inc_pr_min(ptr);
	}
	ft_print_ulprec2(nbr, ptr);
}

void	ft_print_ulmin_uzer(unsigned long int *nbr, int len, t_env *ptr)
{
	ptr->pr_i = 0;
	if (ptr->flag_pm != -1)
		len++;
	while (ptr->pr_i < (ptr->width - len)
		|| ((ptr->width == len) && (ptr->pr_i == 0)))
	{
		if (ptr->zer != 1 || (ptr->zer != 1 && ptr->prec < len)
		|| (ptr->zer == 1 && ptr->width > ptr->prec && ptr->prec != -1))
			write(1, " ", 1);
		else if (ptr->pr_i < ptr->width - ft_get_atr_length(*nbr) && *nbr < 0)
		{
			*nbr = -*nbr;
			wr_inc_pr_min(ptr);
		}
		if (ptr->zer == 1 && !(ptr->zer == 1
		&& ptr->width > ptr->prec && ptr->prec != -1))
			write(1, "0", 1);
		ptr->pr_i++;
		(ptr->wr)++;
	}
	if (*nbr < 0 && ptr->min != 1)
	{
		*nbr = -*nbr;
		wr_inc_pr_min(ptr);
	}
}

void	ft_print_low_hex_nbr(unsigned long int nbr, t_env *ptr)
{
	char c;

	if (nbr > 15)
	{
		ft_print_low_hex_nbr((nbr / 16), ptr);
		ft_print_low_hex_nbr((nbr % 16), ptr);
	}
	else
	{
		if (nbr > 9)
		{
			c = nbr + 87;
			write(1, &c, 1);
			ptr->wr++;
		}
		else
		{
			c = nbr + '0';
			write(1, &c, 1);
			ptr->wr++;
		}
	}
}

void	ft_print_low_hex(unsigned long int nbr, t_env *ptr)
{
	if (ptr->prec != -1 && ft_get_atr_length(nbr) < ptr->prec)
		ft_print_ulprec(nbr, ptr);
	else
	{
		if (ptr->min == 1 && ptr->prec != 0)
		{
			ft_print_low_hex_nbr(nbr, ptr);
			ft_print_ulmin_uzer(&nbr, ft_get_atr_length(nbr), ptr);
		}
		else
		{
			if (ptr->prec == 0 && nbr == 0 && ptr->width == -1)
				;
			else
			{
				ft_print_ulmin_uzer(&nbr, ft_get_atr_length(nbr), ptr);
				if (ptr->prec == 0 && nbr == 0 && ptr->width != -1)
					wr_inc_pr_spc(ptr);
				else
					ft_print_low_hex_nbr(nbr, ptr);
			}
		}
	}
}
