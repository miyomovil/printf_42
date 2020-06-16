/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:02:28 by antomart          #+#    #+#             */
/*   Updated: 2020/02/28 11:01:36 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_str_utils(char *str, t_env *ptr)
{
	wr_inc_pr_str(str, ptr);
	ft_print_bl_spac((ptr->width - ft_strlen(str)), ptr);
}

int		ft_c_null(char **str, t_env *ptr)
{
	if (*str == NULL)
	{
		ft_strdup("(null)");
	}
	if (ptr->prec == 0)
	{
		ptr->wr +=
		ft_print_bl_spac((ptr->width), ptr);
		free(*str);
		return (1);
	}
	return (0);
}

void	ft_print_prec_str(char *str, t_env *ptr)
{
	ptr->pr_i = 0;
	if (ptr->min == -1)
		ft_print_bl_spac(ft_get_spa(str, ptr), ptr);
	ptr->pr_i = 0;
	ptr->pr_i = 0;
	while (ptr->pr_i < ptr->prec && str[ptr->pr_i])
	{
		write(1, &str[ptr->pr_i], 1);
		ptr->wr++;
		ptr->pr_i++;
	}
	if (ptr->min == 1)
		ft_print_bl_spac(ft_get_spa(str, ptr), ptr);
}

void	ft_print_str(va_list list, t_env *ptr)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = ft_strdup(("(null)"));
	else
		str = ft_strdup(str);
	ptr->pr_i = 0;
	if ((ptr->prec != -1 && ptr->prec > ptr->width) ||
	(ptr->prec != -1 && ptr->prec < ft_strlen(str)))
	{
		ft_print_prec_str(str, ptr);
		free(str);
		return ;
	}
	if (ptr->width > 0 && ptr->min != -1)
		ft_print_str_utils(str, ptr);
	else
	{
		ft_print_bl_spac((ptr->width - ft_strlen(str)), ptr);
		ptr->pr_i = 0;
		wr_inc_pr_str(str, ptr);
	}
	free(str);
}
