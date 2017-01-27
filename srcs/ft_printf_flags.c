/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:50:11 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:41:16 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_gettypeflags(t_input *input)
{
	int i;

	i = 0;
	while (input->flags[i])
	{
		if (input->flags[i] == 'l' || input->flags[i] == 'j')
		{
			input->flagl = 1;
			break ;
		}
		if (input->flags[i] == 'h')
			input->flagh++;
		if (input->flags[i] == 'z')
		{
			input->flagz = 1;
			break ;
		}
		i++;
	}
	if (input->flagl || input->flagh || input->flagz)
		input->islong = 1;
}

void	ft_callflags(t_input *input, char *str)
{
	if (input->flagminus)
		str = ft_flagwidth(input, str, 1);
	if (input->flagzero)
		str = ft_flagwidth(input, str, 0);
	if (input->flagpound)
		str = ft_flagpound(input, str);
	if (input->flagplus && !input->negative && ft_tolower(input->c) != 'u'
		&& ft_tolower(input->c) != 'o' && ft_strcmp(str, "(null)"))
		str = ft_flagplus(input, str);
	if (input->negative)
		str = ft_addnegative(input, str);
	if (input->flagspace && !input->flagminus && !input->negative
		&& input->c != 'u' && input->c != '%' && input->flagplus != -1
		&& ft_strcmp(str, "(null)") && ft_tolower(input->c) != 'c')
		str = ft_flagspace(str);
	if (input->width && !input->flagminus)
		str = ft_flagwidth(input, str, 0);
	if (input->c == 'X')
		ft_touppercase(str);
	if (str)
		input->str = ft_strjoin(input->str, str);
}

void	ft_checkflags(t_input *t, char *str)
{
	int		i;
	int		numcheck;

	i = -1;
	numcheck = 0;
	if (str[0] == '-')
		str = ft_deletenegative(t, str);
	if (t->c != '%')
		str = ft_checkprecision(t, str);
	while (t->flags[++i])
	{
		if ((t->flags[i] >= '1' && t->flags[i] <= '9') || t->flags[i] == '.')
			numcheck++;
		if (t->flags[i] == '+' && ft_tolower(t->c) != 'c')
			t->flagplus++;
		if (t->flags[i] == '#' && ft_strcmp(str, "0"))
			t->flagpound++;
		if (t->flags[i] == '-')
			t->flagminus++;
		if (t->flags[i] == ' ' && str[0] != '-')
			t->flagspace++;
		if (t->flags[i] == '0' && !numcheck)
			t->flagzero++;
	}
	ft_callflags(t, str);
}
