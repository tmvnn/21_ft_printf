/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/04 22:21:54 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "../includes/ft_printf.h"

int		main()
{
	int nc = 0;
	int d1=-123, d2=12, d3=2147483647;
	unsigned long t = 42;
	//printf ("%d\n%6d\n%d\n",d1,d2,d3);
	printf("\nnc = %d", printf("\n")); //printf("%8%   %+.4d\n", d1, d2);
	//printf("nc = %d\n\n", nc);
	printf("\nnc = %d", ft_printf("\n")); //ft_printf("%5%   %+.4d\n", d1, d2);
	//printf("nc = %d\n", nc);

	return (0);
}

