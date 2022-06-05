/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:43:17 by gdominic          #+#    #+#             */
/*   Updated: 2022/05/24 23:13:19 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n, int counter)
{
	if (n > 9)
		counter = ft_putnbr_u(n / 10, counter);
	ft_putchar(n % 10 + '0');
	return (counter + 1);
}
