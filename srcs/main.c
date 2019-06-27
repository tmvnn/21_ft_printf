/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/06/27 01:12:06 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "../includes/ft_printf.h"

int		main()
{
	int nc = 0;
	int d1=-123, d2=12, d3=1543;
	//printf ("%d\n%6d\n%d\n",d1,d2,d3);
	nc = printf("%.8d%%   %+.4d\n", d1, d2);
	printf("nc = %d\n\n", nc);
	nc = ft_printf("%.8d%%   %+.4d\n", d1, d2);
	printf("nc = %d\n", nc);
	return (0);
}
