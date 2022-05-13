/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:02:59 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/13 15:01:50 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		putnbr_base(unsigned long long n, char *base, unsigned int base_real);
int		ft_putstr(char *str, int fd);
size_t	ft_strlen(const char *str);
int		print_type(char c, va_list ap);
int		print_type1(char c, va_list ap);
int		print_type2(char c, va_list ap);
int		ft_printf(const char *str, ...);

#endif