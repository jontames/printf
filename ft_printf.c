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
#include <stdio.h>

int	ft_type(char const *arg, va_list d_type, int chs_written)
{
	if (*arg == 'c')
		chs_written += ft_putchar(va_arg(d_type, int));
	else if (*arg == 's')
		chs_written += ft_putstr(va_arg(d_type, char *));
	else if (*arg == 'p')
		chs_written += ft_putptr(va_arg(d_type, void *));
/*	else if (*arg == 'd')
		chs_written += ;
	else if (*arg == 'i')
		chs_written += ;
	else if (*arg == 'u')
		chs_written += ;
	else if (*arg == 'x')
		chs_written += ;
	else if (*arg == 'X')
		chs_written += ;
	else if (*arg == '%')
		chs_written += ; */
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
	printf("%d\n", ft_printf("%p\n", "g"));
}
