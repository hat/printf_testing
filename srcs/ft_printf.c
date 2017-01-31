/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:45:00 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:28:03 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_pickconverscontd picks the conversion function to call
**
** @param t_input stores everything needed for the return string
*/

void	ft_pickconverscontd(t_input *input)
{
	if (input->c == 'n')
		ft_convers_n(input);
	if (input->c == 'b')
		ft_convers_b(input);
	if (input->c == 'Z' || input->c == 'R')
		ft_convers_other(input);
}

/*
** ft_pickconverscontd picks the conversion function to call
**
** @param t_input stores everything needed for the return string
*/

void	ft_pickconvers(t_input *input)
{
	if (input->c != '%' && input->c != 'n' && input->c != '\n')
		input->var = va_arg(input->ap, void *);
	if (input->c == 'i' || input->c == 'd' || input->c == 'D')
		ft_convers_id(input);
	if (input->c == 's')
		ft_convers_s(input);
	if (input->c == 'c')
		ft_convers_c(input);
	if (input->c == 'C')
		ft_convers_wc(input);
	if (input->c == 'S')
		ft_convers_ws(input);
	if (input->c == 'f')
		ft_convers_f(input);
	if (input->c == '%')
		ft_convers_percent(input);
	if (input->c == 'o' || input->c == 'O')
		ft_convers_o(input);
	if (input->c == 'x' || input->c == 'X')
		ft_convers_x(input);
	if (input->c == 'u' || input->c == 'U')
		ft_convers_u(input);
	if (input->c == 'p')
		ft_convers_p(input);
	ft_pickconverscontd(input);
}

/*
** ft_pickconvers finds the conversion and sets the struct variable
**
** @param t_input stores everything needed for the return string
*/

void	ft_findconvers(t_input *input)
{
	int		i;
	char	c;

	i = -1;
	while (input->form[++i])
	{
		c = input->form[i + 1];
		if (ft_isconversion(c))
		{
			input->c = c;
			ft_pickconvers(input);
			break ;
		}
	}
	input->form = input->form + 1;
	ft_init(input);
}

/*
** ft_percentsign checks to see if a percent sign exists in form
**
** @param t_input stores everything needed for the return string
*/

void	ft_percentsign(t_input *input)
{
	char	*prev;
	char	*temp;

	prev = ft_strndup(input->form, (ft_strchr(input->form, '%') - input->form));
	input->form = input->form + (ft_strchr(input->form, '%') - input->form);
	ft_resetflags(input);
	input->negative = 0;
	if (!input->str)
		input->str = ft_strdup(prev);
	else
	{
		temp = ft_strdup(input->str);
		ft_strdel(&input->str);
		input->str = ft_strjoin(temp, prev);
		ft_strdel(&temp);
	}
	ft_strdel(&prev);
	ft_findconvers(input);
}

/*
** ft_printf function to a string that could have variables present
**
** @param format pointer to the string to print
**
** @return length of the string that is printed
*/

int		ft_printf(const char *format, ...)
{
	t_input	*input;
	int		ret;

	input = ft_init_tinput(format);
	va_start(input->ap, format);
	ft_init(input);
	va_end(input->ap);
	ret = 0;
	while (input->str[ret])
	{
		if (input->str[ret] == 1)
			input->str[ret] = 0;
		ret++;
	}
	write(1, input->str, ret);
	ft_strdel(&input->flags);
	ft_strdel(&input->str);
	free(input);
	return (ret);
}
