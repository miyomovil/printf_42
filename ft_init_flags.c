/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:00:12 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 10:59:41 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_flags(t_env *ptr)
{
	ptr->min = -1;
	ptr->zer = -1;
	ptr->width = -1;
	ptr->prec = -1;
	ptr->flag_pm = -1;
}

void	ft_init_flags2(t_env *ptr)
{
	ptr->wr = 0;
	ptr->i = 0;
	ptr->flag_pw = -1;
}

void	i_n_wr_inc(t_env *ptr)
{
	ptr->i++;
	ptr->wr++;
}
