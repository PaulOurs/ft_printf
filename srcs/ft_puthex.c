/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:06:23 by paubello          #+#    #+#             */
/*   Updated: 2024/11/17 07:32:45 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, base) + ft_puthex(n % 16, base);
	else
		count += ft_putchar(base[n]);
	return (count);
}
