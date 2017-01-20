/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:13:10 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:45:47 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_itoa_base(int value, int base)
{
	long 	n;
	long	temp;
	long	len;
	char 	*numstr;
	char 	*basenum;

	len = 0;
	basenum = "0123456789abcdef";
	temp = value;
	n = value;
	if (value < 0)
	{
		if (base == 10 || base == 8)
			len++;
		n = n * -1;
	}
	if (!value)
		return ("0");
	while (value)
	{
		value /= base;
		len++;
	}
	numstr = (char *)malloc(sizeof(char) * len + 1);
	if (!numstr)
		return (0);
	numstr[len] = '\0';
	while (n)
	{
		numstr[--len] = basenum[n % base];
		n /= base;
	}
	if (temp < 0)
	{
		if (base == 10)
			numstr[0] = '-';
		if (base == 8)
			numstr[0] = '3';
	}
	return (numstr);
}
