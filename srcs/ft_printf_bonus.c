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
	int		len;
	int		*holdmem;

	flags = 1;
	holdmem = va_arg(input->ap, int *);
	len = (int)ft_strlen(input->str);
	holdmem = &len;
	input->form = input->form + flags;
	return (0);
}