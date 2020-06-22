/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:00:50 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:24:10 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_prec2(int nbr, t_env *ptr)
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

void	ft_print_min_zer(int *nbr, int len, t_env *ptr)
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

void	ft_print_prec(int nbr, t_env *ptr)
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
	ft_print_prec2(nbr, ptr);
}

void	ft_print_nbr(int nbr, t_env *ptr)
{
	long	nb;
	char	c;

	nb = nbr;
	if (nb == -2147483648 && (ptr->min == -1))
		long_int_min_spc(ptr);
	else
		ft_print_nbr2(nb, c, ptr);
}

void	ft_print_int(int nbr, t_env *ptr)
{
	if (ptr->prec != -1 && ft_get_atr_length(nbr) < ptr->prec)
		ft_print_prec(nbr, ptr);
	else
	{
		if (ptr->min == 1)
		{
			ft_print_nbr(nbr, ptr);
			ft_print_min_zer(&nbr, ft_get_atr_length(nbr), ptr);
		}
		else
		{
			if (ptr->prec == 0 && nbr == 0 && ptr->width == -1)
				;
			else
			{
				ft_print_min_zer(&nbr, ft_get_atr_length(nbr), ptr);
				if (ptr->prec == 0 && nbr == 0 && ptr->width != -1)
					wr_inc_pr_spc(ptr);
				else
					ft_print_nbr(nbr, ptr);
			}
		}
	}
}
