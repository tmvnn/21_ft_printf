/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/19 18:26:51 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxX%", c) != 0);
}

int		is_valid(const char c)
{
	return (is_conversion(c) || 0);
}

void	parse_spec(const char *str, int *i)
{}

void	parse_str(const char *str, int *i)
{
	(*i)++;
	if (is_valid(str[*i])) //!
		parse_spec(str, i);
}

int		ft_printf(const char * restrict str, ...)
{
	va_list argptr;
	int		i;
	int		delt;

	va_start(argptr, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			delt = i;
			parse_str(str, &i);
		}
		else if (str[i])
			write(1, &str[i], 1);
	}
	va_end(argptr);
	return (0);
}
