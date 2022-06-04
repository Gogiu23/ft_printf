/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertx.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:46:03 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/04 22:13:59 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_convertx(unsigned int num, int base, int mode)
{
	int		i;
	int		counter;
	char	*rep; 
	char	*buffer;

	counter = 0;
	buffer = (char *)malloc(sizeof(char) * 9);
	if (mode)
		rep = "0123456789ABCDEF";
	else
		rep = "0123456789abcdef";
	while(num != 0)
	{
		buffer[counter] = rep[num % base];
		num /= base;
		counter++;
	}
	buffer[counter] = '\0';
	i = counter;
	while (i > 0)
	{
		ft_putchar(buffer[i - 1]);
		i--;
	}
	free(buffer);
	return (counter);
}
