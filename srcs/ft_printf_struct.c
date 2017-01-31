/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:03:52 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:44:46 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_resetflags resets all the flags of the struct
**
** @param input the struct holding all the output variables
*/

void	ft_resetflags(t_input *input)
{
	input->width = 0;
	input->negative = 0;
	input->precision = -1;
	input->flagplus = 0;
	input->flagpound = 0;
	input->flagspace = 0;
	input->flagminus = 0;
	input->flagzero = 0;
	input->islong = 0;
	input->flagl = 0;
	input->flagh = 0;
	input->flagz = 0;
}

/*
** ft_init initializes the string depending on whether a percent sign was found
**
** @param input the struct holding all the output variables
*/

int		ft_init(t_input *input)
{
	if (!(ft_strchr(input->form, '%')))
	{
		if (!input->str)
			input->str = ft_strdup(input->form);
		else if (*input->form)
			input->str = ft_strjoin(input->str, input->form);
	}
	else
		ft_percentsign(input);
	return (0);
}

/*
** ft_init_tinput initializes the struct
**
** @param format the string passed in
**
** @return the newly initialized struct
*/

t_input	*ft_init_tinput(const char *format)
{
	t_input	*new;

	new = (t_input *)ft_memalloc(sizeof(t_input));
	new->form = ft_strdup((char *)format);
	new->precision = -1;
	return (new);
}
