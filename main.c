/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/10 13:53:22 by timuryakubo      ###   ########.fr       */
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

	printf("\nnc = %d", printf("%.1s\n", "a")); //printf("%8%   %+.4d\n", d1, d2);
	printf("\nnc = %d", ft_printf("@moulitest: %#.x %#.0x", 0, 0)); //ft_printf("%5%   %+.4d\n", d1, d2);

	return (0);
}

