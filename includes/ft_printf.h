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
# include <limits.h>

typedef struct		s_pf_flags
{
	int				hash;//
	int				zero;//
	//int				neg;
	int				minus;//
	int				plus;//
	int				space;//
	//int				prec;
	int				fwidth;
}				t_pf_flags;

typedef struct		s_pf
{
	int				i;
	int				num_of_c;
	va_list			argptr;
	char			*out;
	int				n_len;
	t_pf_flags		flag;
	int				prec;
	int				is_neg;
}					t_pf;

/*
** ---------------------------- Main Functions ------------------------------
*/

int				ft_printf(const char * restrict format, ...);
int				is_conversion(const char c);
int				is_flag(const char c);
int				is_precision(const char c);
int				is_valid(const char c);
void			init_flags(t_pf *pf);
void			parse_str(const char *str, t_pf *pf);
void			parse_flag(const char *str, t_pf *pf);
void			parse_prec(const char *str, t_pf *pf);
void			parse_spec(const char *str, t_pf *pf);
void			s_percent(t_pf *pf);
void			s_int(t_pf *pf);
void 			get_sign_info(t_pf *pf);
void			print_inum(t_pf *pf);
void			print_width(t_pf *pf);
void			print_sign(t_pf *pf);

/*
** ----------------------------- libft Functions -------------------------------
*/

char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
void			*ft_memset(void *b, int c, size_t len);

#endif
