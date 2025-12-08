/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:19:47 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/05 17:20:31 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_printf(unsigned long n, char *base)
{
	int				len;
	int				nb;
	unsigned long	b;

	nb = 0;
	len = ft_strlen(base);
	if (n >= (unsigned long)len)
		nb += ft_putnbr_base_printf(n / len, base);
	b = n % len;
	nb += ft_putchar_printf(base[b]);
	return (nb);
}
