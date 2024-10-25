/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:50 by jtames            #+#    #+#             */
/*   Updated: 2024/10/25 20:57:53 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_puthex(unsigned long n, char const arg)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_puthex((n / 16), arg);
	if ((n % 16) <= 9)
		len += ft_putchar((n % 16) + '0');
	else if (arg == 'x' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_putchar((n % 16) - 10 + 'a');
	else if (arg == 'X' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_putchar((n % 16) - 10 + 'A');
	return (len);
}
