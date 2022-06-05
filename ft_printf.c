/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:13:38 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/04 22:04:12 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	int	ft_splitter(char const *src, va_list ptr);

int	ft_printf(char const *src, ...)
{
	int		counter;
	va_list	ptr;

	counter = 0;
	va_start(ptr, src);
	while (*src != '\0')
	{
		if(*src != '%')
		{
			ft_putchar(*src);
			counter++;
		}
		else
		{
			src++;
			counter += ft_splitter(src, ptr);
		}
		src++;
	}
	va_end(ptr);
	return (counter);
}

static	int	ft_splitter(char const *src, va_list ptr)
{
	int count;
	count = 0;

	if (*src == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (*src  == 'd' || *src  == 'i')
		return (count += ft_putnbr(va_arg(ptr, int), count));
	if (*src == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	if (*src == 'x')
		return (count += ft_convertx(va_arg(ptr, unsigned int), 16, 0));
	return(count);
}
/*
int	main(void)
{
	char  *s;
	int	  x;
	int	  d;
	char  c;
//	int re;
//	int re2;
	//system("clear");
	s = "ciao figo";
	x = 23;
	d = -212;
	c = 'h';
	ft_printf("Mi dice %s, %d, %c, %x\n", s, d, c, x);
	printf("Mi dice %s, %d, %c, %x\n", s, d, c, x);
//	int k = ft_printf("%d\n", d);
//	printf("k = %d\n", k);
//	int j = printf("%d\n", d);
//	printf("j = %d\n", j);
	return (0);
}*/
