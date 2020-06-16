/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:02:48 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:51:05 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_uprec2(unsigned int nbr, t_env *ptr)
{
	while (ptr->pr_i < ptr->prec - ft_get_atr_length(nbr))
	{
		write(1, "0", 1);
		ptr->pr_i++;
		(ptr->wr)++;
	}
	ft_print_nbr(nbr, ptr);
	while (ptr->width > ptr->wr)
	{
		wr_inc_pr_spc(ptr);
		ptr->pr_i++;
	}
}

void	ft_print_umin_uzer(unsigned int *nbr, int len, t_env *ptr)
{
	ptr->pr_i = 0;
	while (ptr->pr_i < (ptr->width - len))
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

void	ft_print_uprec(unsigned	int nbr, t_env *ptr)
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
	ft_print_uprec2(nbr, ptr);
}

void	ft_print_unbr(unsigned int nbr, t_env *ptr)
{
	long	nb;
	char	c;

	nb = nbr;
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
			ft_print_unbr((nb) / 10, ptr);
			ft_print_unbr((nb) % 10, ptr);
		}
		else
		{
			c = (nb) + '0';
			write(1, &c, 1);
			(ptr->wr)++;
		}
	}
}

void	ft_print_uint(unsigned int nbr, t_env *ptr)
{
	if (ptr->prec != -1 && ft_get_atr_length(nbr) < ptr->prec)
		ft_print_prec(nbr, ptr);
	else
	{
		if (ptr->min == 1)
		{
			ft_print_unbr(nbr, ptr);
			ft_print_umin_uzer(&nbr, ft_get_atr_length(nbr), ptr);
		}
		else
		{
			if (ptr->prec == 0 && nbr == 0 && ptr->width == -1)
				;
			else
			{
				ft_print_umin_uzer(&nbr, ft_get_atr_length(nbr), ptr);
				if (ptr->prec == 0 && nbr == 0 && ptr->width != -1)
					wr_inc_pr_spc(ptr);
				else
					ft_print_unbr(nbr, ptr);
			}
		}
	}
}
