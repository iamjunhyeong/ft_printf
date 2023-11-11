/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:50:14 by junhyeop          #+#    #+#             */
/*   Updated: 2023/11/11 20:22:05 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_type(const char c, va_list listp)
{
	if (c == 'c')
		return (ft_print_c(va_arg(listp, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(listp, char *)));
	else if (c == 'p')
		return (ft_print_p(va_arg(listp, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_d(va_arg(listp, int)));
	else if (c == 'u')
		return (ft_print_u(va_arg(listp, unsigned int)));
	else if (c == 'x')
		return (ft_print_sx(va_arg(listp, unsigned int)));
	else if (c == 'X')
		return (ft_print_bx(va_arg(listp, unsigned int)));
	else if (c == '%')
		return (ft_print_c('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int	idx;
	int	len;
	int cnt;
	va_list listp;

	va_start(listp, format);
	idx = 0;
	cnt = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
			len = check_type(format[++idx], listp);
		else if (format[idx])
			len = ft_print_c(format[idx]);
		if (len < 0)
			return (-1);
		cnt += len;
		idx++;
	}
	va_end(listp);
	return (cnt);
}