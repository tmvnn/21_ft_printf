/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/19 18:03:59 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "../includes/ft_printf.h"

int		main()
{
	//printf("%.2s", "Hello\n");
	int d1=123, d2=12, d3=1543;
	//printf ("%d\n%6d\n%d\n",d1,d2,d3);
	printf("%D\n", d1);
	ft_printf("%d\n", d1);
	return (0);
}
