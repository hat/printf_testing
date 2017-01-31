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

/*
** ft_vartype changes the null to pointer from va_args to a variable type
**            depending on the flags for signed numbers
**
** @param input the struct holding all the output variables
**
** @return the number from va_args
*/

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

/*
** ft_vartype_u changes the null to pointer from va_args to a variable type
**            depending on the flags for unsigned numbers
**
** @param input the struct holding all the output variables
**
** @return the number from va_args
*/

unsigned long	ft_vartype_u(t_input *input)
{
	unsigned long	num;

	ft_gettypeflags(input);
	if (input->flagl || input->c == 'U' || input->c == 'O')
		num = (unsigned long)input->var;
	else if (input->flagh == 1)
		num = (unsigned short)input->var;
	else if (input->flagh == 2)
		num = (unsigned char)input->var;
	else if (input->flagz)
		num = (size_t)input->var;
	else
		num = (unsigned int)input->var;
	return (num);
}

/*
** ft_getconversion returns the conversion in the string
**
** @param str current str passed in
**
** @return the character of the conversion
*/

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

/*
** ft_isflag checks to see if the character is a flag
**
** @param c the character to check
**
** @return bool whether or not it is a flag
*/

int				ft_isflag(char c)
{
	if (c == '#' || c == '-' || c == '0')
	{
		return (1);
	}
	return (0);
}

/*
** ft_isconversion checks to see if the character is a conversion
**
** @param c the character to check
**
** @return bool whether or not the char is a conversion
*/

int				ft_isconversion(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'c'
			|| c == '%' || c == 'f' || c == 'o' || c == 'x'
			|| c == 'u' || c == 'O' || c == 'X' || c == 'p'
			|| c == 'U' || c == 'D' || c == 'C' || c == 'S'
			|| c == 'n' || c == 'b' || c == 'Z' || c == 'R')
	{
		return (1);
	}
	return (0);
}
