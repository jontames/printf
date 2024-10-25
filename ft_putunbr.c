/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:55:42 by jtames            #+#    #+#             */
/*   Updated: 2024/10/25 20:55:48 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunbr(n / 10);
		len += ft_putunbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
