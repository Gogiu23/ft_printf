/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:03:03 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/04 18:29:21 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n, int counter)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		counter = ft_putnbr(n / 10, counter);
	ft_putchar(n % 10 + '0');
	return (counter + 1);
}
