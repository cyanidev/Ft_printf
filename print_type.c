/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:17:33 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/13 17:17:33 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(char c, va_list ap)
{
	int	ret;

	ret = 0;
	if (c == 'd' || c == 'i' || c == 'p' || c == 'x')
		ret = ret + print_type1(c, ap);
	else if (c == 'c' || c == 's' || c == 'u' || c == 'X')
		ret = ret + print_type2(c, ap);
	else
		ret = ret + write(1, &c, 1);
	return (ret);
}

int	print_type1(char c, va_list ap)
{
	int		ret;
	int		n;
	char	minus;

	ret = 0;
	if (c == 'd' || c == 'i')
	{
		minus = '-';
		n = va_arg(ap, int);
		if (n <= -1)
		{
			ret = ret + write(1, &minus, 1);
			ret = ret + putnbr_base((unsigned)(n * -1), "0123456789", 10);
		}
		else
		ret = ret + putnbr_base(n, "0123456789", 10);
	}
	else if (c == 'p')
	{
		ret = ret + write(1, "0x", 2);
		ret = ret + putnbr_base(va_arg(ap, size_t), "0123456789abcdef", 16);
	}
	else if (c == 'x')
		ret = ret + putnbr_base(va_arg(ap, unsigned), "0123456789abcdef", 16);
	return (ret);
}

int	print_type2(char c, va_list ap)
{
	int	a;
	int	ret;

	ret = 0;
	if (c == 'c')
	{
		a = va_arg(ap, int);
		ret = ret + write(1, &a, 1);
	}
	else if (c == 's')
		ret = ret + ft_putstr(va_arg(ap, char *), 1);
	else if (c == 'u')
		ret = ret + putnbr_base(va_arg(ap, unsigned int), "0123456789", 10);
	else if (c == 'X')
		ret = ret + putnbr_base(va_arg(ap, unsigned), "0123456789ABCDEF", 16);
	return (ret);
}

/* c imprime caracter ascii correspondiente
d i decimal con signo de un entero
x X conversion hexadecimal
p puntero
o octal nosigned
u decimal unsigned
s string
% el mismo */