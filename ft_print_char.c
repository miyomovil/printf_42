/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:17:11 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 10:26:25 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char_width(t_env *ptr)
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

void	ft_print_char(va_list list, t_env *ptr)
{
	char c;

	c = va_arg(list, int);
	if (ptr->width != -1 && ptr->min != 1)
		ft_print_char_width(ptr);
	write(1, &c, 1);
	if (ptr->width != 1 && ptr->min == 1)
		ft_print_char_width(ptr);
	ptr->wr++;
}
