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
	int counter;
	char  *symbols;
	char  *buffer;
	char  *ptr;

	counter = 0;
	buffer = (char *)malloc(sizeof(char) * 9);
	if (!buffer)
		return (0);
	if (mode == 0)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	ptr = &buffer[8];
	*ptr = '\0';
	while (num != 0)
	{
		*ptr = symbols[num%base];
		num /= base;
		ptr++;
	}
	while (*ptr >= 0)
	{
<<<<<<< HEAD
		counter = ft_putchar(buffer[i - 1]);
		i--;
=======
		counter = ft_putchar(*ptr);
		ptr--;
>>>>>>> 942a8463afdce64774c8a3fee7abab0fbd27c8f8
	}
	free(buffer);
	return (counter);
}
