/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:00:10 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/13 16:46:33 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ret = ret + write(1, "%", 1);
			else
				ret = ret + print_type(str[i], ap);
		}
		else if (str[i] != '%')
			ret = ret + write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}

/*int main()
{
	int a;
	a = ft_printf("hola %s %c %d %u %p %x %X %ww\n", NULL, 0, 0, 0, NULL, 0, 0);
	printf("Mio: %d\n", a);
	sleep(2);
	a = printf("hola %s %c %d %u %p %x %X %ww\n", NULL, 0, 0, 0, NULL, 0, 0);
	printf("Ori: %d\n", a);
}*/
/*ap = argument pointer*/