/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:40:11 by jtames            #+#    #+#             */
/*   Updated: 2024/10/21 19:40:13 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(char const *arg, ...);
int	ft_putchar(char c);
int	ft_putstr(char const *c);
int	ft_putptr(void *c);

#endif
