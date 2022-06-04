/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:30:25 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/04 22:03:50 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(const char c);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n, int count);
int		ft_convertx(unsigned int num, int base, int mode);
int		ft_putstr(const char *s);

#endif
