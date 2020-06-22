/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:35:45 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 14:27:50 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_percw(t_env *ptr)
{
	int i;

	i = 0;
	while (i < ptr->width - 1)
	{
		if (ptr->zer == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ptr->wr++;
		i++;
	}
}

void	ft_print_perc(va_list list, t_env *ptr)
{
	if (ptr->width != -1 && ptr->min != 1)
		ft_print_percw(ptr);
	write(1, "%", 1);
	if (ptr->width != 1 && ptr->min == 1)
		ft_print_percw(ptr);
	ptr->wr++;
}
