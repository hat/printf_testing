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

int		ft_atoi_flags(const char *str)
{
	int		ans;
	int		i;
	int		neg;

	ans = 0;
	i = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32 || ft_isflag(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return (ans * neg);
}

int		ft_widthtopositive(t_input *input, int num)
{
	if (num < 0)
	{
		input->flagminus = 1;
		num *= -1;
	}
	return (num);
}

int		ft_checkforwild(char *str, int iswidth)
{
	int		i;
	int		wildflag;

	i = 0;
	wildflag = 0;
	while (str[i] && !ft_isconversion(ft_tolower(str[i])) && !wildflag)
	{
		if (iswidth && str[i] == '.')
			break ;
		if (str[i] == '*')
			wildflag = 1;
		i++;
	}
	return (wildflag);
}

void	ft_getflagprecision(t_input *input)
{
	int		i;
	int		precision;

	i = 0;
	while (input->flags[i] && input->flags[i] != '.')
		i++;
	if (input->flags[i] == '.')
	{
		if (ft_checkforwild(&input->flags[i], 0))
		{
			precision = (int)input->var;
			if (precision >= 0)
				input->precision = precision;
			input->var = va_arg(input->ap, void *);
		}
		else
			input->precision = ft_atoi_flags(&input->flags[i + 1]);
	}
}

int		ft_getflags(t_input *input)
{
	int		i;
	int		wildflag;
	char	*c;

	i = 1;
	wildflag = 0;
	c = ft_strdup(input->form + 1);
	while (input->form[i] && !ft_isconversion(ft_tolower(input->form[i])))
		i++;
	c[i - 1] = '\0';
	input->flags = ft_strdup(c);
	if (ft_checkforwild(input->flags, 1))
	{
		input->width = ft_widthtopositive(input, (int)input->var);
		if (ft_atoi_flags(input->flags + 1))
			input->width = ft_atoi_flags(input->flags + 1);
		input->var = va_arg(input->ap, void *);
	}
	else
		input->width = ft_atoi_flags(input->flags);
	ft_getflagprecision(input);
	ft_strdel(&c);
	return (ft_strlen(input->flags));
}
