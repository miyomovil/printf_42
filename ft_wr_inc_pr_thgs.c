/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr_inc_pr_thgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:15:25 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:43:13 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	wr_inc_pr_spc(t_env *ptr)
{
	write(1, " ", 1);
	(ptr->wr)++;
}

void	wr_inc_pr_min(t_env *ptr)
{
	write(1, "-", 1);
	(ptr->wr)++;
}

void	wr_inc_pr_zer(t_env *ptr)
{
	write(1, "0", 1);
	(ptr->wr)++;
}

void	wr_inc_pr_str(char *str, t_env *ptr)
{
	while (str[ptr->pr_i])
	{
		write(1, &str[ptr->pr_i], 1);
		ptr->wr++;
		ptr->pr_i++;
	}
}
