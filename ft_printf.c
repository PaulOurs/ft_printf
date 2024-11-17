/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:48:25 by paubello          #+#    #+#             */
/*   Updated: 2024/11/17 07:29:46 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	handle_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}

static int	parse_format(const char *format, va_list arg)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		count += handle_ptr(va_arg(arg, void *));
	else if (*format == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (*format == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (*format == 'u')
		count += ft_putunbr(va_arg(arg, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			count += parse_format(++format, arg);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
