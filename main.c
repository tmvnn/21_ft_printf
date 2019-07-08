/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/08 18:59:13 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "../includes/ft_printf.h"

int		main()
{
	int nc = 0;
	int d1=-123, d2=12, d3=2147483647;
	int t = 28;

	//printf("\nnc = %d", printf("%Xi", t)); //printf("%8%   %+.4d\n", d1, d2);
	//printf("\nnc = %d", ft_printf("%Xi", t)); //ft_printf("%5%   %+.4d\n", d1, d2);
	printf("%s\n", ft_iltoa_base(2127, 10));

	return (0);
}

