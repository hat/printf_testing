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

void	ft_callflags(t_input *input, char *str)
{
	if (input->flagminus)
		str = ft_flagwidth(input, str, 1);
	if (input->flagzero)
		str = ft_flagwidth(input, str, 0);
	if (input->flagpound)
		str = ft_flagpound(input, str);
	if (input->flagplus && !input->negative && ft_tolower(input->c) != 'u')
		str = ft_flagplus(input, str);
	if (input->negative)
		str = ft_addnegative(input, str);
	if (input->flagspace && !input->flagminus && !input->negative && input->c != 'u' 
		&& input->c != '%' && input->flagplus != -1)
		str = ft_flagspace(str);
	if (input->width && !input->flagminus)
		str = ft_flagwidth(input, str, 0);
	if (input->c == 'X')
		ft_touppercase(str);
	if (str)
		input->str = ft_strjoin(input->str, str);
}

void	ft_checkflags(t_input *input, char *str)
{
	int		i;
	int		numcheck;

	i = -1;
	numcheck = 0;
	if (str[0] == '-')
		str = ft_deletenegative(input, str);
	if (input->c != '%')
		str = ft_checkprecision(input, str);
	while (input->flags[++i])
	{
		if ((input->flags[i] >= '1' && input->flags[i] <= '9')
			|| input->flags[i] == '.')
			numcheck++;
		if (input->flags[i] == '+' && ft_tolower(input->c) != 'c')
			input->flagplus++;
		if (input->flags[i] == '#' && ft_strcmp(str, "0"))
			input->flagpound++;
		if (input->flags[i] == '-')
			input->flagminus++;
		if (input->flags[i] == ' ' && str[0] != '-')
			input->flagspace++;
		if (input->flags[i] == '0' && !numcheck)
			input->flagzero++;
	}
	ft_callflags(input, str);
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
			if (precision > 0)
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
		input->var = va_arg(input->ap, void *);
	}
	else
		input->width = ft_atoi_flags(input->flags);
	ft_getflagprecision(input);
	ft_strdel(&c);
	return (ft_strlen(input->flags));
}
