/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_negative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:46:52 by thendric          #+#    #+#             */
/*   Updated: 2017/01/13 14:46:59 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_addnegative adds the minus sign to the str
**
** @param input the struct holding all the output variables
** @param str the current string
**
** @return the new string
*/

char	*ft_addnegative(t_input *input, char *str)
{
	char	*new;

	input->negative = input->negative;
	new = NULL;
	new++;
	new = ft_strdup(str);
	new--;
	new[0] = '-';
	ft_strdel(&str);
	return (new);
}

/*
** ft_deletenegative adds the minus sign to the str
**
** @param input the struct holding all the output variables
** @param str the current string
**
** @return the new string
*/

char	*ft_deletenegative(t_input *input, char *str)
{
	char	*new;

	input->negative = 1;
	new = NULL;
	new = ft_strdup(str + 1);
	ft_strdel(&str);
	return (new);
}
