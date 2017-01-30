/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:47:45 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:41:55 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convers_n(t_input *input)
{
	int		flags;
	int		*mem;

	flags = 1;
	mem = va_arg(input->ap, int *);
	*mem = (int)ft_strlen(input->str);
	input->form = input->form + flags;
	return (0);
}

int		ft_convers_b(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype(input);
	numstr = ft_itoa_base_long(num, 2);
	ft_checkflags(input, numstr);
	input->form = input->form + flag;
	return (0);
}

void	ft_convers_other(t_input *input)
{
	int		flag;
	char	*str;

	flag = 0;
	while (input->form[flag] != 'Z' && input->form[flag] != 'R')
		flag++;
	ft_getflags(input);
	str = ft_strdup(&input->c);
	ft_checkflags(input, str);
	input->form = input->form + flag;
}
