/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_universal_helpers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:51:30 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:46:56 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_gettypeflags(t_input *input)
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

long			ft_vartype(t_input *input)
{
	long	num;

	ft_gettypeflags(input);
	if (input->flagl || input->c == 'D')
		num = (long)input->var;
	else if (input->flagh == 1)
		num = (short)input->var;
	else if (input->flagh == 2)
		num = (signed char)input->var;
	else if (input->flagz)
		num = (size_t)input->var;
	else
		num = (int)input->var;
	return (num);
}

unsigned long	ft_vartype_u(t_input *input)
{
	unsigned long	num;

	ft_gettypeflags(input);
	if (input->flagl || input->flagh || input->flagz || input->c == 'U'
		|| input->c == 'O')
		num = (unsigned long)input->var;
	else
		num = (unsigned int)input->var;
	return (num);
}

char			ft_getconversion(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_isconversion(str[i]))
			return (str[i]);
		i++;
	}
	return (' ');
}

int				ft_isflag(char c)
{
	if (c == '#' || c == '-' || c == '0')
	{
		return (1);
	}
	return (0);
}

int				ft_isconversion(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'c'
			|| c == '%' || c == 'f' || c == 'o' || c == 'x'
			|| c == 'u' || c == 'O' || c == 'X' || c == 'p'
			|| c == 'U' || c == 'D' || c == 'C' || c == 'S'
			|| c == 'n')
	{
		return (1);
	}
	return (0);
}
