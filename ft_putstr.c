
#include "ft_printf.h"

int	ft_putstr(char const *c)
{
	int		len;

	if (*c == '\0')
		return (0);
	len = 0;
	while (*c != '\0')
	{
		len += ft_putchar(*c);
		c++;
	}
	return (len);
}
