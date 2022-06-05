/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:44:56 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/04 21:46:47 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
		write (1, s, ft_strlen(s));
	return (ft_strlen(s));
}
