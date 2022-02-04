/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:43:48 by bshintak          #+#    #+#             */
/*   Updated: 2021/11/20 15:49:25 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_letters(char a)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i'
		|| a == 'u' || a == 'x' || a == 'X' || a == '%')
		return (1);
	return (0);
}

int	ft_conversions(char conv, va_list args)
{
	int	counter;

	counter = 0;
	if (conv == 'c')
		counter += (ft_putchar((char)va_arg(args, int)));
	else if (conv == 's')
		counter += (ft_putstr(va_arg(args, char *)));
	else if (conv == 'p')
		counter += (ft_pointer(va_arg(args, unsigned long)));
	else if (conv == 'd' || conv == 'i')
		counter += (ft_putnumber(va_arg(args, int)));
	else if (conv == 'u')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789"));
	else if (conv == 'x')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (conv == 'X')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (conv == '%')
		counter += (ft_putchar('%'));
	return (counter);
}

int	ft_start(const char *format, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (format[i])
	{
		if (!format)
			return (counter);
		if (format[i] == '%')
		{
			i++;
			if (ft_letters(format[i]))
				counter += ft_conversions(format[i], args);
			else
				return (counter);
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start (args, format);
	i = ft_start(format, args);
	va_end(args);
	return (i);
}
