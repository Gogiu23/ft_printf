/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:13:38 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/06 18:28:16 by gdominic         ###   ########.fr       */
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
		if (*src != '%')
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
	int	count;

	count = 0;
	if (*src == '%')
		return (count += ft_putchar(*src));
	if (*src == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (*src == 'd' || *src == 'i')
		return (count += ft_putnbr(va_arg(ptr, int), count));
	if (*src == 's')
		return (count += ft_putstr(va_arg(ptr, char *)));
	if (*src == 'x')
		return (count += ft_convertx(va_arg(ptr, unsigned int), 16, 1));
	if (*src == 'X')
		return (count += ft_convertx(va_arg(ptr, unsigned int), 16, 0));
	if (*src == 'u')
		return (count += ft_putnbr_u(va_arg(ptr, unsigned int), count));
	return (count);
}
/*
int	main(void)
{
	char		  *s;
	int			  x;
	int			  d;
	char		  c;
	unsigned int  u;
	int re;
	int re2;
	//system("clear");
	s = "ciao figo";
	x = -10;
	s = "ciao vecio";
	d = -212;
	c = 'h';
	u = 10;
//	re = ft_printf("Mi dice %s, %d, %c, %x, %u, %%\n", s, d, c, -8, u);
//	re2 = printf("Mi dice %s, %d, %c, %x, %u, %%\n", s, d, c, x, u);
	re = ft_printf("%x ", 0);
	re2 = printf("%x ", 0);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", -10);
	re2 = printf("%x ", -10);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", -200000);
	re2 = printf("%x ", -200000);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", -6000023);
	re2 = printf("%x ", -6000023);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 10);
	re2 = printf("%x ", 10);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 10000);
	re2 = printf("%x ", 10000);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 100023);
	re2 = printf("%x ", 100023);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 0xabcdef);
	re2 = printf("%x ", 0xabcdef);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 0x7fedcba1);
	re2 = printf("%x ", 0x7fedcba1);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 2147483647);
	re2 = printf("%x ", 2147483647);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", -2147483648);
	re2 = printf("%lx ", -2147483648);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x ", 4294967295);
	re2 = printf("%lx ", 4294967295);
	printf(" re is: %d, re2 is %d\n", re, re2);
	re = ft_printf("%x%xx%x ", 1, 2, -3);
	re2 = printf("%x%xx%x ", 1, 2, -3);
	printf(" re is: %d, re2 is %d\n", re, re2);

	printf("%x", -10);
	printf("%x", -200000);
	printf("%x", -6000023);
	printf("%x", 10);
	printf("%x", 10000);
	printf("%x", 100023);
	printf("%x", 0xabcdef);
	printf("%x", 0x7fedcba1);
	printf("%x", 2147483647);
	printf("%x", -2147483648);
	printf("%x", 4294967295);
	printf("dgs%xxx", 10);
	printf("%x%xx%x", 1, 2, -3);
	re2 = printf("%x ", -10);

	printf("re is: %d, re2 is %d\n", re, re2);
//	int k = ft_printf(" %x ", -42);
//	printf("k = %d\n", k);
//	int j = printf(" %x ", -42);
//	printf("j = %d\n", j);
	return (0);
}*/
