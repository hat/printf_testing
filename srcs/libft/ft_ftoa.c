/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:43:18 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:44:19 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_numdigits(long value, long precision)
{
	long	len;

	len = 0;
	if (value < 0)
		value *= -1;
	while (value >= 1)
	{
		value /= 10;
		len++;
	}
	if (precision > 0)
		len++;
	len += precision;
	return (len);
}

char	*ft_getdot(char *str, long value, long precision)
{
	long	dot;

	if (!strchr(str, '.'))
		return (str);
}

char	*ft_ftoa(float value, long	precision)
{
	int		neg;
	long	size;
	long	temp;
	char	*numstr;

	neg = 0;
	temp = value;
	printf("Val: %f Temp: %lu\n", value, temp);
	if (value <= 0)
		neg = 1;
	if (neg)
		temp *= -1;
	size = ft_numdigits(value, precision) + neg;
	printf("Size: %lu\n", size);
	if (!(numstr = ft_strnew(size)))
		return (0);
	numstr[size--] = '\0';
	ft_getdot(numstr, value, precision);
	if (temp == 0)
		numstr[0] = '0';
	while (temp != 0)
	{
		numstr[size--] = (temp % 10) + '0';
		temp /= 10;
	}
	if (neg && numstr[0] != '0')
		numstr[0] = '-';
	return (numstr);
}

int		main(void)
{
	char	*str;

	str = ft_ftoa(12.45, 5);
	printf("%s\n", str);
	return (0);
}
