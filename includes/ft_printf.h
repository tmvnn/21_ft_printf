/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:22:41 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/17 23:28:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 3
# define PF_FLAG "df"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_pf
{
	int				i;
	int				num_of_c;
	va_list			argptr;
	char			*out;
}					t_pf;

/*
** ---------------------------- Main Functions ------------------------------
*/

int				ft_printf(const char * restrict format, ...);

/*
** ----------------------------- libft Functions -------------------------------
*/

char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);

#endif
