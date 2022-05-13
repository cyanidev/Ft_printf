/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:15:17 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/13 16:58:54 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(unsigned long long n, char *base, unsigned int base_real)
{
	int	ret;

	ret = 0;
	if (n >= base_real)
		ret = ret + putnbr_base(n / base_real, base, base_real);
	ret = ret + write(1, &base[(n % base_real)], 1);
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str, int fd)
{
	int	ret;

	ret = 0;
	if (!str)
		ret = ret + write(1, "(null)", 6);
	else if (str)
		ret = ret + write(fd, &str[0], ft_strlen(str));
	return (ret);
}

/*int main()
{
	char *str;
	str = "hola";
	ft_putstr(str, 1);
}*/

/*int main()
{
	unsigned long int n;
	n = 0;

	putnbr_base(n, "0123456789ABCDEF", 16);
}*/
