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

void    print_sign(t_pf *pf)
{
	if (pf->flag.plus)
	{
		pf->num_of_c += pf->is_neg ? write(1, "-", 1) : write(1, "+", 1);
	}
	else if (pf->is_neg)
		pf->num_of_c += write(1, "-", 1);
}

void	print_inum(t_pf *pf)
{
	print_sign(pf);
	pf->num_of_c += write(1, pf->out, pf->n_len);
	free(pf->out);
	//pf->i++;
}

void	s_int(t_pf *pf)
{
	int		num;

	num = va_arg(pf->argptr, int);
	pf->out = ft_itoa(num);
	get_sign_info(pf);
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

void	init_flags(t_pf *pf)
{
	pf->is_neg = 0;
	pf->n_len = 0;
	pf->flag.hash = 0;
	pf->flag.zero = 0;
	pf->flag.minus = 0;
	pf->flag.plus = 0;
	pf->flag.space = 0;
	pf->flag.fwidth = 0;
}

void    parse_flag(const char *str, t_pf *pf)
{
	init_flags(pf);
	while(is_flag(str[pf->i]))
	{
		str[pf->i] == '#' ? pf->flag.hash = 1 : 0;
		str[pf->i] == '0' ? pf->flag.zero = 1 : 0;
		str[pf->i] == '-' ? pf->flag.minus = 1 : 0;
		str[pf->i] == '+' ? pf->flag.plus = 1 : 0;
		str[pf->i] == ' ' ? pf->flag.space = 1 : 0;
		if (str[pf->i] >= '1' && str[pf->i] <= '9')
		{
			pf->flag.fwidth = ft_atoi(str + pf->i);
			while (str[pf->i] >= '0' && str[pf->i] <= '9')
				pf->i++;
		}
		else
			pf->i++;
	}
}

void	parse_str(const char *str, t_pf *pf)
{
	pf->i++;
	if (is_valid(str[pf->i])) //!
	{
		parse_flag(str, pf);
		parse_spec(str, pf);
		printf("%d\n", pf->flag.fwidth);
	}
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
	return (pf.num_of_c);
}
