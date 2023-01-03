#include "ft_printf_short_version.h"

void	ft_putstr(char *str, int *i)
{
	if (!str)
		str = "(null)";
	while (*str)
		*i += write(1, str++, 1);
}

void	ft_putchar(char c, int *i)
{
	*i += write(1, &c, 1);
}

void	ft_putnummm(long long int num, int base, int *i, int status)
{
	char *hex1 = "0123456789abcdef";
	char *hex2 = "0123456789ABCDEF";

	if (num < 0)
	{
		num *= -1;
		*i += write(1, "-", 1);
	}
	if (num >= base)
		ft_putnummm((num / base), base, i, status);
	if (status == 1)
		*i += write(1, &hex1[num % base], 1);
	else if (status == 2)
		*i += write(1, &hex2[num % base], 1);
}

void	ft_pointer(long long int num, int base, int *i)
{
	if (num == 0)
		*i += write(1, "0x0", 3);
	else
	{
		*i += write(1, "0x", 2);
		ft_putnummm(num, base, i, 1);
	}
}

int	ft_printf_s(const char *format, ...)
{
	int len = 0;
	va_list	wtv;

	va_start(wtv, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
				ft_putchar((char)va_arg(wtv, int), &len);
			else if (*format == 's')
				ft_putstr(va_arg(wtv, char *), &len);
			else if (*format == 'd' || *format == 'i')
				ft_putnummm((long long int)va_arg(wtv, int), 10, &len, 1);
			else if (*format == 'x')
				ft_putnummm((long long int)va_arg(wtv, unsigned int), 16, &len, 1);
			else if (*format == 'X')
				ft_putnummm((long long int)va_arg(wtv, unsigned int), 16, &len, 2);
			else if (*format == 'p')
				ft_pointer((long long int)va_arg(wtv, unsigned long), 16, &len);
			else if (*format == '%')
				ft_putchar('%', &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(wtv), len);
}

int main ()
{
	void	*pointer = NULL;
	ft_printf_s("%c\n", 'c');
	printf("%c\n", 'c');
	printf("--------------------------------\n");
	ft_printf_s("%s\n", "hello");
	printf("%s\n", "hello");
	printf("--------------------------------\n");
	ft_printf_s("%d\n", 2147483647);
	printf("%d\n", 123456);
	printf("--------------------------------\n");
	ft_printf_s("%i\n", 123456);
	printf("%i\n", 123456);
	printf("--------------------------------\n");
	ft_printf_s("%x\n", 123);
	printf("%x\n", 123);
	printf("--------------------------------\n");
	ft_printf_s("%X\n", 2147483647);
	printf("%X\n", 2147483647);
	printf("--------------------------------\n");
	ft_printf_s("%p\n", &pointer);
	printf("%p\n", &pointer);
	printf("--------------------------------\n");
	ft_printf_s("%%\n");
	printf("%%\n");
	printf("--------------------------------\n");
}
