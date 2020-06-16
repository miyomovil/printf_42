/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_atr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:48 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:02:44 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_atr_nbr(const char *str, t_env *ptr)
{
	int nbr;

	nbr = -1;
	while (ft_isdigit(str[ptr->cnt]))
	{
		if (nbr == -1)
			nbr = str[ptr->cnt] - '0';
		else
			nbr = nbr * 10 + (str[ptr->cnt] - '0');
		ptr->cnt++;
	}
	return (nbr);
}

int	ft_get_atr_length(long int nbr)
{
	int len;

	if (nbr < 0)
		len = 1;
	else
		len = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len + 1);
}

int	ft_print_bl_spac(int len, t_env *ptr)
{
	ptr->pr_i = -1;
	while (++ptr->pr_i < len)
	{
		if (ptr->zer == 1)
			wr_inc_pr_zer(ptr);
		else
			wr_inc_pr_spc(ptr);
		if (ptr->pr_i == -1)
			ptr->pr_i = 0;
	}
	return (ptr->pr_i);
}

int	ft_get_spa(char *str, t_env *ptr)
{
	if (ptr->width > 0 && ptr->prec > ft_strlen(str))
		return (ptr->width - ft_strlen(str));
	else
		return (ptr->width - ptr->prec);
}
