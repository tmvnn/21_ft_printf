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

void	print_inum(t_pf *pf)
{
	write(1, pf->out, ft_strlen(pf->out));
	free(pf->out);
	//pf->i++;
}

void	s_int(t_pf *pf)
{
	int		num;

	num = va_arg(pf->argptr, int);
	pf->out = ft_itoa(num);
	print_inum(pf);
}

void	parse_spec(const char *str, t_pf *pf)
{
	if (str[pf->i] == '%')
	{
		//double percent
	}
	if (str[pf->i] == 'd' || str[pf->i] == 'D' || str[pf->i] == 'i')
		s_int(pf);
}

void	parse_str(const char *str, t_pf *pf)
{
	pf->i++;
	if (is_valid(str[pf->i])) //!
		parse_spec(str, pf);
}

void	init_params(t_pf *pf)
{
	pf->i = -1;
	pf->num_of_c = 0;
}

int		ft_printf(const char * restrict str, ...)
{
	va_list argptr;
	int		i;
	int		delt;
	t_pf	pf;

	va_start(pf.argptr, str);
	init_params(&pf);
	while (str[++pf.i])
	{
		if (str[pf.i] == '%')
		{
			delt = pf.i;
			parse_str(str, &pf);
		}
		else if (str[pf.i])
			pf.num_of_c += write(1, &str[pf.i], 1);
	}
	va_end(pf.argptr);
	return (0);
}
