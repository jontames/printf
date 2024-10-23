
#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_puthex(n, 'x');
	}
	return (len);
}
