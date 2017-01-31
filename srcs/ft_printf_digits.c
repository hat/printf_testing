/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:48:42 by thendric          #+#    #+#             */
/*   Updated: 2017/01/13 14:38:41 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_convers_id changes the conversion to an integer or double
**
** @param t_input stores everything needed for the return string
*/

void	ft_convers_id(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype(input);
	numstr = ft_itoa_base_long(num, 10);
	ft_checkflags(input, numstr);
	input->form = input->form + flag;
}

/*
** ft_convers_u changes the conversion to an unsigned integer or long
**
** @param t_input stores everything needed for the return string
*/

void	ft_convers_u(t_input *input)
{
	int				flag;
	unsigned long	num;
	char			*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype_u(input);
	numstr = ft_itoa_base_unsign(num, 10);
	ft_checkflags(input, numstr);
	input->form = input->form + flag;
	ft_strdel(&numstr);
}

/*
** ft_convers_f changes the conversion to a float - NOT WORKING
**
** @param t_input stores everything needed for the return string
*/

void	ft_convers_f(t_input *input)
{
	input = NULL;
}

/*
** ft_convers_o changes the conversion to an octal value
**
** @param t_input stores everything needed for the return string
*/

void	ft_convers_o(t_input *input)
{
	int		i;
	int		flag;
	long	num;
	char	*numstr;

	i = 0;
	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype_u(input);
	numstr = ft_itoa_base_unsign(num, 8);
	ft_checkflags(input, numstr);
	input->form += flag;
	ft_strdel(&numstr);
}

/*
** ft_convers_x changes the conversion to a hexedecimal value
**
** @param t_input stores everything needed for the return string
*/

void	ft_convers_x(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype_u(input);
	if (input->islong)
		numstr = ft_itoa_base_unsign(num, 16);
	else
		numstr = ft_itoa_base_long(num, 16);
	ft_checkflags(input, numstr);
	input->form += flag;
	ft_strdel(&numstr);
}
