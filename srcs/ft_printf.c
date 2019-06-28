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

void		parse_str(const char *str, t_pf *pf)
{
	pf->i++;
	if (is_valid(str[pf->i])) //!
	{
		parse_flag(str, pf);
		parse_spec(str, pf);

	}
}

void		init_params(t_pf *pf)
{
	pf->i = -1;
	pf->num_of_c = 0;
}

int			ft_printf(const char * restrict str, ...)
{
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
	return (pf.num_of_c);
}
