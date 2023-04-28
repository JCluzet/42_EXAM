#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ps(char *s, int *l)
{
	if(!s)
		s = "(null)";
	while(*s)
		*l += write(1, s++, 1);
}

void	pd(long long int n, int b, int *l)
{
	char *h="0123456789abcdef";
	if (n < 0)
	{
		n *= -1;
		*l += write(1, "-", 1);
	}
	if (n >= b)
		pd((n/b), b, l);
	*l += write(1, &h[n % b], 1);
}

int	ft_printf(const char *f, ...)
{
	int l = 0;
	va_list p;
	va_start(p, f);
	while(*f)
	{
		if ((*f == '%') && *(f + 1))
		{
			f++;
			if (*f == 's')
				ps(va_arg(p, char *), &l);
			else if (*f == 'd')
				pd((long long int)va_arg(p, int), 10, &l);
			else if (*f == 'x')
				pd((long long int)va_arg(p, unsigned int), 16, &l);
		}
		else
			l += write(1, f, 1);
		f++;
	}
	return(va_end(p), l);
}
