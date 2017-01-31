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

/*
** ft_poset checks the offset for the precision by figuring out
**          what will be added to the string in the future
**
** @param input the struct holding all the output variables
**
** @return the number of chars that will be added
*/

int		poset(t_input *input)
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

/*
** ft_checkprecision uses the precision to update the string
**
** @param input the struct holding all the output variables
** @str the current string
**
** @return the new string
*/

char	*ft_checkprecision(t_input *input, char *str)
{
	char	*new;
	char	*fill;

	if (input->precision > (int)ft_strlen(str) && ft_tolower(input->c) != 's')
	{
		fill = ft_strnew(input->precision - ft_strlen(str) - poset(input));
		ft_memset(fill, '0', input->precision - ft_strlen(str) - poset(input));
		new = ft_strjoin(fill, str);
		ft_strdel(&fill);
	}
	else
	{
		if (input->precision != -1 && ft_tolower(input->c) == 's')
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
