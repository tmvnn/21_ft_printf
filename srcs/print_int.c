/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/14 17:26:16 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    print_sign(t_pf *pf)
{
	if (pf->flag.plus || pf->flag.space)
		pf->buff[pf->ib++] = pf->flag.plus ? '+' : ' ';
	else if (pf->is_neg)
		pf->buff[pf->ib++] = '-';
}


void	print_hash(t_pf *pf)
{
	if (pf->out[0] == 0 && pf->n_len == 0)
			return ;
	pf->buff[pf->ib++] = '0';
	pf->tp == 'x' || pf->tp == 'p' ? pf->buff[pf->ib++] = 'x' : 0;
	pf->tp == 'X' ? pf->buff[pf->ib++] = 'X' : 0;
	pf->tp == 'x' || pf->tp == 'X' || pf->tp == 'p' ? pf->flag.fwidth -= 2 : pf->flag.fwidth--;
}

void    print_width(t_pf *pf)
{
	int i;

	i = -1;
	(pf->flag.plus || pf->flag.space || pf->is_neg) ? pf->flag.fwidth-- : 0;
	if (pf->flag.zero && pf->flag.hash)
		print_hash(pf);
	while (pf->flag.fwidth - pf->n_len > ++i)
		pf->buff[pf->ib++] = pf->flag.zero ? '0' : ' ';
}

void	put_num_2_buff(t_pf *pf)
{
	int i;

	i = -1;
	while (pf->out[++i])
		pf->buff[pf->ib++] = pf->out[i];
}

void	print_inum(t_pf *pf)
{
	if (pf->flag.zero)
	{
		print_sign(pf);
		print_width(pf);
		put_num_2_buff(pf);
	}
	else if(pf->flag.minus)
	{
		print_sign(pf);
		put_num_2_buff(pf);
		print_width(pf);
	}
	else
	{
		print_width(pf);
		print_sign(pf);
		put_num_2_buff(pf);
	}
}
