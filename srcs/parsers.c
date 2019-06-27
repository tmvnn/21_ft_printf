/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/19 18:26:51 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		s_percent(t_pf *pf)
{
	if (pf->flag.minus)
	{} //
	else //
	{} //
	pf->num_of_c += write(1, "%", 1);
}

void		parse_spec(const char *str, t_pf *pf)
{
	if (str[pf->i] == '%')
		s_percent(pf);
	if (str[pf->i] == 'd' || str[pf->i] == 'D' || str[pf->i] == 'i')
		s_int(pf);
}

void		init_flags(t_pf *pf)
{
	pf->is_neg = 0;
	pf->n_len = 0;
	pf->prec = -1;
	pf->flag.hash = 0;
	pf->flag.zero = 0;
	pf->flag.minus = 0;
	pf->flag.plus = 0;
	pf->flag.space = 0;
	pf->flag.fwidth = 0;
}

void		parse_prec(const char *str, t_pf *pf)
{
	pf->i++;
	if (pf->prec >= 0)
		return ;
	pf->prec = ft_atoi(str + pf->i);
	while (str[pf->i] >= '0' && str[pf->i] <= '9')
		pf->i++;
}

void    	parse_flag(const char *str, t_pf *pf)
{
	init_flags(pf);
	while (is_flag(str[pf->i]) || is_precision(str[pf->i]))
	{
		str[pf->i] == '#' ? pf->flag.hash = 1 : 0;
		str[pf->i] == '0' ? pf->flag.zero = 1 : 0;
		str[pf->i] == '-' ? pf->flag.minus = 1 : 0;
		str[pf->i] == '+' ? pf->flag.plus = 1 : 0;
		str[pf->i] == ' ' ? pf->flag.space = 1 : 0;
		if (str[pf->i] == '.')
			parse_prec(str, pf);
		else if (str[pf->i] >= '1' && str[pf->i] <= '9')
		{
			pf->flag.fwidth = ft_atoi(str + pf->i);
			while (str[pf->i] >= '0' && str[pf->i] <= '9')
				pf->i++;
		}
		else
			pf->i++;
	}
}
