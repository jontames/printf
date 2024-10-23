
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
