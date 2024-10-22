
#include "ft_printf.h"
#include <stdio.h>

int	ft_putptr(void *c)
{
	printf("%s\n", (char *)&c);
	return (5);
}
