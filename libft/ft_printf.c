/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:09:24 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/05 17:22:16 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_percent_p(void *p)
{
	int	nb;

	nb = 0;
	if (!p)
		nb += ft_putstr_printf("(nil)");
	else
	{
		nb += ft_putstr_printf("0x");
		nb += ft_putnbr_base_printf((unsigned long)p, "0123456789abcdef");
	}
	return (nb);
}

static int	ft_percent_nb(char c, va_list args)
{
	int				nb;
	unsigned int	u;

	nb = 0;
	if (c == 'd' || c == 'i')
		nb += ft_putnbr_printf(va_arg(args, int));
	else if (c == 'u')
		nb += ft_putnbr_base_printf(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
	{
		u = va_arg(args, unsigned int);
		nb += ft_putnbr_base_printf(u, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		u = va_arg(args, unsigned int);
		nb += ft_putnbr_base_printf(u, "0123456789ABCDEF");
	}
	else
		ft_putchar_printf(c);
	return (nb);
}

static int	ft_percent(char c, va_list args)
{
	int	nb;

	nb = 0;
	if (c == 'c')
		nb += ft_putchar_printf((char)va_arg(args, int));
	else if (c == 's')
		nb += ft_putstr_printf(va_arg(args, char *));
	else if (c == '%')
		nb += ft_putchar_printf('%');
	else if (c == 'p')
		nb += ft_percent_p(va_arg(args, void *));
	else
		nb += ft_percent_nb(c, args);
	return (nb);
}

int	ft_printf(const char *str, ...)
{
	int		nb;
	va_list	args;

	nb = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			nb += ft_putchar_printf(*str);
		else if (*str == '%')
		{
			str++;
			nb += ft_percent(*str, args);
		}
		str++;
	}
	va_end(args);
	return (nb);
}
