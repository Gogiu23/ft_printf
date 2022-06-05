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
	int	  counter;
	char  *rep;
	char  *ptr;
	char  *buffer;
	buffer = (char *)malloc(sizeof(char) * 50);

	if (mode == 0)
		rep = "0123456789ABCDEF";
	rep = "0123456789fedcba";
	ptr = &buffer[49];
	counter = 0;
	*ptr = '\0';
	while(num != 0)
	{
		*--ptr = rep[num%base];
		num /= base;
//		counter += ft_putchar(*ptr);
		write (1, ptr, 1);
	}
	free(buffer);
	return (counter);
}
