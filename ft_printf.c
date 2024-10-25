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

int	ft_type(char const *arg, va_list d_type)
{
	int		chs_written;

	chs_written = 0;
	if (*arg == 'c')
		chs_written += ft_putchar(va_arg(d_type, int));
	else if (*arg == 's')
		chs_written += ft_putstr(va_arg(d_type, char const *));
	else if (*arg == 'p')
		chs_written += ft_putptr(va_arg(d_type, unsigned long));
	else if (*arg == 'd' || *arg == 'i')
		chs_written += ft_putdinbr(va_arg(d_type, int));
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
			chs_written += ft_type(arg, d_type);
		}
		else
			chs_written += ft_putchar(*arg);
		arg++;
	}
	va_end(d_type);
	return (chs_written);
}

/* int	main()
{
	char	*a = "";
	// int		b = -547;
	
	printf("------mia------\n");
	printf("%d\n", ft_printf("%s\n", a));
	printf("------original------\n");
	printf("%d\n", printf("%s\n", a));
} */

/* int main(void)
{
    int n = 42;
    unsigned int un = -42;
    char c = '\0';
    char *s = NULL;
    char *ptr = "Test";
    int rlen1 = 0, rlen2 = 0;
    // Test 1: Mix
    rlen1 = ft_printf("\033[0;33mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m", c, s, n, n, un, n, n, s);
    rlen2 = printf("\033[0;32mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m", c, s, n, n, un, n, n, s);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 2: Char
    rlen1 = ft_printf("\033[0;33mTest char: %c\n\033[0m", 'A');
    rlen2 = printf("\033[0;32mTest char: %c\n\033[0m", 'A');
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 3: String
    rlen1 = ft_printf("\033[0;33mTest string: %s\n\033[0m", "mundo");
    rlen2 = printf("\033[0;32mTest string: %s\n\033[0m", "mundo");
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 4: Hex minusculas
    rlen1 = ft_printf("\033[0;33mTest hex: %x\n\033[0m", 25555555);
    rlen2 = printf("\033[0;32mTest hex: %x\n\033[0m", 25555555);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 5: Puntero
    rlen1 = ft_printf("\033[0;33mTest ptr: %p\n\033[0m", ptr);
    rlen2 = printf("\033[0;32mTest ptr: %p\n\033[0m", ptr);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 6: Hex mayusculas
    rlen1 = ft_printf("\033[0;33mTest HEX: %X\n\033[0m", 255);
    rlen2 = printf("\033[0;32mTest HEX: %X\n\033[0m", 255);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 7: Decimal
    rlen1 = ft_printf("\033[0;33mTest dec: %d\n\033[0m", 777);
    rlen2 = printf("\033[0;32mTest dec: %d\n\033[0m", 777);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 8: Int
    rlen1 = ft_printf("\033[0;33mTest int: %i\n\033[0m", 777);
    rlen2 = printf("\033[0;32mTest int: %i\n\033[0m", 777);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 9: Unsigned int
    rlen1 = ft_printf("\033[0;33mTest uns: %u\n\033[0m", -0);
    rlen2 = printf("\033[0;32mTest uns: %u\n\033[0m", -0);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 10: Porcentaje
    rlen1 = ft_printf("\033[0;33mTest porcentaje: %%\n\033[0m");
    rlen2 = printf("\033[0;32mTest porcentaje: %%\n\033[0m");
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    // Test 11: Locura
    rlen1 = ft_printf("\033[0;33mTest locura: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n\033[0m", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    rlen2 = printf   ("\033[0;32mtest locura: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n\033[0m", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    printf("\n\n");
    rlen1 = ft_printf("\033[0;33mTest locura:%c%s%d%i%u%x\n\033[0m", 'B', "-42", -42, -42 ,-42 ,-42);
    rlen2 = printf   ("\033[0;32mtest locura:%c%s%d%i%u%x\n\033[0m", 'B', "-42", -42, -42 ,-42 ,-42);
    
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    
    printf("\n\n");
    return 0;
} */
