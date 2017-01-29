/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:47:45 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:41:55 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convers_percent(t_input *input)
{
	int		flag;
	char	*str;

	flag = 1;
	str = ft_strnew(1);
	str[0] = '%';
	flag += ft_getflags(input);
	ft_checkflags(input, str);
	input->form = input->form + flag;
	ft_strdel(&str);
	return (0);
}

int		ft_convers_c(t_input *input)
{
	int		flag;
	char	*c;
	int		i;

	flag = 1;
	i = -1;
	if (input->form[1] == 'l' && input->form[2] == 'c')
	{
		ft_convers_wc(input);
		return (0);
	}
	c = ft_strnew(1);
	flag += ft_getflags(input);
	c[0] = (int)input->var;
	if (c[0] == 0)
		c[0] = 1;
	ft_checkflags(input, c);
	input->form += flag;
	return (0);
}

int		ft_convers_s(t_input *input)
{
	int		flag;
	char	*str;
	char	*temp;
	int		i;

	flag = 1;
	i = -1;
	if (input->form[1] == 'l' && input->form[2] == 's')
	{
		ft_convers_ws(input);
		return (0);
	}
	flag += ft_getflags(input);
	temp = (char *)input->var;
	if (!temp)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(temp);
	ft_checkflags(input, str);
	input->form += flag;
	ft_strdel(&str);
	return (0);
}

int		ft_convers_p(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = (long)input->var;
	numstr = ft_itoa_base_long(num, 16);
	ft_checkflags(input, numstr);
	input->form += flag;
	ft_strdel(&numstr);
	return (0);
}
