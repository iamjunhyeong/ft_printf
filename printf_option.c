/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:58:35 by junhyeop          #+#    #+#             */
/*   Updated: 2023/11/11 20:26:19 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_c(int c)
{
	if (!c)
		return (-1);
	if (write(1, &c, 1) == -1)
		return (0);
	return (1);
}

int	ft_print_s(char *s)
{
	if (!s)
		return (-1);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return ft_strlen(s);
}

void	ft_putadr(unsigned long long adr, int caps)
{
	char	digits[] = "0123456789abcdef0123456789ABCDEF";

	if (adr >= 16)
	{
		ft_putadr(adr / 16, caps);
		write(1, &digits[adr % 16 * caps], 1);
	}
	else if (adr > 0)
	{
		write(1, &digits[adr % 16 * caps], 1);
	}
}

int	ft_print_p(void *p)
{
	if (!p)
		return (-1);
	write(1, "0x", 2);
	ft_putadr((unsigned long long)p, 0);
	return 1;
}

int	ft_print_d(int d)
{
	char	*str;

	str = ft_itoa(d);
	if (!str)
		return (-1);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_u(unsigned int u)
{
	char	*str;

	if (u < 0)
		return (-1);
	str = ft_itoa_un(u);
	if (!str)
		return (-1);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_sx(unsigned int x)
{
	ft_putadr((unsigned long long)x, 0);
	return 1;
}

int ft_print_bx(unsigned int x)
{
	ft_putadr((unsigned long long)x, 1);
	return 1;
}