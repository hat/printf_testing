/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:02:08 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:50:24 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precoffset(t_input *input)
{
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	if (input->c == ft_tolower('o'))
	{
		while (input->flags[i])
		{
			if (input->flags[i] == '#')
				offset += 1;
			i++;
		}
	}
	return (offset);
}

char	*ft_checkprecision(t_input *input, char *str)
{
	char	*new;
	char	*fill;

	if (input->precision > (int)ft_strlen(str) && ft_tolower(input->c) != 's'
		&& ft_tolower(input->c) != 'c')
	{
		fill = ft_strnew(input->precision - ft_strlen(str) - ft_precoffset(input));
		ft_memset(fill, '0', input->precision - ft_strlen(str) - ft_precoffset(input));
		new = ft_strjoin(fill, str);
		ft_strdel(&fill);
	}
	else
	{
		if (input->precision != -1 && input->c == 's')
			new = ft_strndup(str, input->precision);
		else if (input->precision == 0 && input->c != '%' && ft_atoi(str) == 0)
		{
			new = ft_strnew(1);
			new = ft_strdup("");
		}
		else
			new = ft_strdup(str);
	}
	return (new);
}
