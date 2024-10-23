/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:39:54 by jtames            #+#    #+#             */
/*   Updated: 2024/10/21 19:39:57 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char const *arg, va_list d_type, int chs_written)
{
	if (*arg == 'c')
		chs_written += ft_putchar(va_arg(d_type, int));
	else if (*arg == 's')
		chs_written += ft_putstr(va_arg(d_type, char const *));
	else if (*arg == 'p')
		chs_written += ft_putptr(va_arg(d_type, unsigned long));
/* 	else if (*arg == 'd' || *arg == 'i')
		chs_written += ft_putdnbr(va_arg(d_type, int)); */
	else if (*arg == 'u')
		chs_written += ft_putunbr(va_arg(d_type, unsigned int));
	else if (*arg == 'x' || *arg == 'X')
		chs_written += ft_puthex(va_arg(d_type, unsigned int), *arg);
	else if (*arg == '%')
		chs_written += ft_putchar('%');
	return (chs_written);
}

int	ft_printf(char const *arg, ...)
{
	int			chs_written;
	va_list		d_type;

	chs_written = 0;
	va_start(d_type, arg);
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			chs_written += ft_type(arg, d_type, chs_written);
		}
		else
			chs_written += ft_putchar(*arg);
		arg++;
	}
	va_end(d_type);
	return (chs_written);
}

int	main()
{
/* 	char	*a = ""; */
	int		b = -547;
	
	printf("------mia------\n");
	printf("%d\n", ft_printf("%u\n", b));
	printf("------original------\n");
	printf("%d\n", printf("%u\n", b));
}
