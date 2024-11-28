/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:56:12 by jtames            #+#    #+#             */
/*   Updated: 2024/10/25 20:56:16 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *c)
{
	int		len;

	if (c == NULL)
		return (ft_putstr("(null)"));
	len = 0;
	while (*c != '\0')
	{
		len += ft_putchar(*c);
		c++;
	}
	return (len);
}
