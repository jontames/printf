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
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(char const *arg, ...);
int	ft_putchar(unsigned char c);
int	ft_putstr(char const *c);
int	ft_putptr(unsigned long n);
int	ft_puthex(unsigned long n, char const arg);
int	ft_putunbr(unsigned int n);
int	ft_putdinbr(int n);

#endif
