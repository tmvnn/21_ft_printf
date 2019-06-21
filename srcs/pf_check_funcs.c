/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:20:25 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/02 20:14:21 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxX%", c) != 0);
}

int		is_flag(const char c)
{
	return (ft_strchr("#0-+ 123456789", c) != 0);
}

int		is_valid(const char c)
{
	return (is_conversion(c) || is_flag(c));
}

void	get_sign_info(t_pf *pf)
{
	char *tmp;

	if (pf->out[0] == '-')
	{
		pf->is_neg = 1;
		tmp = ft_strdup(pf->out + 1);
		free(pf->out);
		pf->out = tmp;
	}
	pf->n_len = (int)ft_strlen(pf->out);
}
