/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/19 18:26:51 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			s_uint(t_pf *pf, char tp)
{
	intmax_t	num;

	pf->flag.plus = 0;
	pf->flag.space = 0;
	num = va_arg(pf->argptr, intmax_t);
	if (tp != 'U' && pf->mod == no_mod)
		pf->out = ft_ultoa((unsigned int)num);
	else if (tp == 'U' || pf->mod == l_mod)
		pf->out = ft_ultoa((unsigned long)num);
	else if (pf->mod == h_mod)
		pf->out = ft_ultoa((unsigned short)num);
	else if (pf->mod == hh_mod)
		pf->out = ft_ultoa((unsigned char)num);
	else if (pf->mod == ll_mod)
		pf->out = ft_ultoa((unsigned long long)num);
	else if (pf->mod == j_mod || pf->mod == t_mod)
		pf->out = ft_ultoa((uintmax_t)num);
	else if (pf->mod == z_mod)
		pf->out = ft_ultoa((size_t)num);
	get_sign_info(pf);
	handle_int_prec(pf);
	print_inum(pf);
	free(pf->out);
	pf->i++;
}
