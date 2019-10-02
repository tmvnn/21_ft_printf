/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:54:30 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>
#include "ft_printf.h"

int		main()
{
	int nc = 0;
	int d1=-123, d2=12, d3=2147483647;
	int t = 28;
	char *s = ft_strdup("AAA");

	printf("\nnc = %d", printf("@main_ftprintf:asda %d asdsad%s\n", 256,s));
	printf("\nnc = %d", ft_printf("@main_ftprintf:asdasd %dasdasd%s\n", 256,s));

	free(s);
	return (0);
}

