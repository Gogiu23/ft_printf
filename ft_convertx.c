/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertx.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:46:03 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/05 20:31:37 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_convertx(unsigned int num, int base, int mode)
{
	int		counter;
	char	*symbols;
	char	*buffer;
	char	*ptr;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	counter = 0;
	buffer = (char *)malloc(sizeof(char) * 9);
	if (!buffer)
		return (0);
	if (mode == 0)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	ptr = &buffer[8];
	free(buffer);
	*ptr = 0;
	while (num != 0)
	{
		*ptr = symbols[num % base];
		num /= base;
		ptr++;
		counter++;
	}
	*ptr = '\0';
	while (*--ptr >= 0)
	{
		if (*ptr != 0)
			ft_putchar(*ptr);
	}
	return (counter);
}
