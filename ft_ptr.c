/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:52:52 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/07 17:58:26 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_realptr(char *newbuff, int i)
{
	int	sizer;

	sizer = 2;
	newbuff[i] = '\0';
	sizer += ft_strlen(newbuff);
	while ((i - 1) >= 0)
	{
		ft_putchar(newbuff[i - 1]);
		i--;
	}
	free(newbuff);
	return (sizer);
}

int	ft_ptr(unsigned long long strike, int nextbase)
{
	int		i;
	char	*convert;
	char	*newbuff;

	if (strike == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	i = 0;
	write (1, "0x", 2);
	convert = "0123456789abcdef";
	newbuff = (char *)malloc(sizeof(char) * 21);
	if (newbuff == 0)
		return (0);
	while (strike != 0)
	{
		newbuff[i] = convert[strike % nextbase];
		strike /= nextbase;
		i++;
	}
	return (ft_realptr(newbuff, i));
}
