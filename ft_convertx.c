/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertx.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:46:03 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/06 20:28:00 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_realconvert(char *buffer, int i)
{
	int	counter;

	counter = 0;
	buffer[i] = '\0';
	counter += ft_strlen(buffer);
	while ((i - 1) >= 0)
	{
		ft_putchar(buffer[i - 1]);
		i--;
	}
	free(buffer);
	return (counter);
}

int	ft_convertx(unsigned int num, int base, int mode)
{
	int		i;
	char	*symbols;
	char	*buffer;

	i = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	buffer = (char *)malloc(sizeof(char) * 9);
	if (!buffer)
		return (0);
	if (mode == 0)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	while (num != 0)
	{
		buffer[i] = symbols[num % base];
		num /= base;
		i++;
	}
	return (ft_realconvert(buffer, i));
}
