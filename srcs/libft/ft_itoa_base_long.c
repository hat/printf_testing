/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:13:10 by thendric          #+#    #+#             */
/*   Updated: 2016/12/28 13:13:12 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Set up for negatives in printf

#include "libft.h"
#include <stdio.h>

char 	*ft_itoa_base_long(long value, int base)
{
	int 	neg;
	int		negoct;
	ssize_t	size;
	size_t	temp;
	char 	*numstr = NULL;
	char 	basenum[17] = "0123456789abcdef";

	neg = 0;
	negoct = 0;
	size = 1;
	temp = value;
	if (base == 8 && value < 0)
		negoct = 1;
	if (base == 10 && value < 0)
	{
		temp *= -1;
		neg = 1;
		size++;
	}

	if (base == 16 && value == 	-2147483648)
		temp *= -1;
	else if (base != 10 && value < 0)
		temp -= -2147483648;
	while ((temp /= base) > 0)
		size++;
	if (!(numstr = ft_strnew(size)))
		return (0);
	numstr[size--] = '\0';
	while (*numstr)
		numstr++;
	if (neg)
		temp = value * -1;
	else
		temp = value;
	while (size >= 0)
	{
		numstr[size] = basenum[temp % base];
		size--;
		temp /= base;
	}
	if (neg)
		numstr[0] = '-';
	if (negoct)
		numstr[0] = '3';
	return (numstr);
}