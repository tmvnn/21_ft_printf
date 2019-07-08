/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iltoa_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/05 22:44:14 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_strmemal(intmax_t num, size_t *size_n, int base)
{
	if (num == LONG_MIN)
	{
		*size_n = 0;
		return (ft_strdup("-9223372036854775808"));
	}
	*size_n = 1;
	if (num < 0)
		*size_n = *size_n + 1;
	while ((num = num / base))
		*size_n = *size_n + 1;
	return (ft_strnew(*size_n));
}

char			*ft_iltoa_base(intmax_t n, int base)
{
	size_t		size_n;
	intmax_t	num;
	char		*str;
	char		*ret;

	if (!(str = ft_strmemal(n, &size_n, base)))
		return (NULL);
	ret = str;
	if ((num = n) < 0 && size_n > 0)
	{
		*str++ = '-';
		num = -num;
		size_n--;
	}
	while (size_n--)
	{
		str[size_n] = num % base < 10 ? num % base + '0' : num % base + 'A' - 10;
		num /= base;
	}
	return (ret);
}
