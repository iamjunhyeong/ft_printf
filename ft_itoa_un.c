/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:23:32 by junhyeop          #+#    #+#             */
/*   Updated: 2023/11/11 20:18:59 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	input_str(char *str, unsigned int n)
{
	int		s;
	int		i;
	char	buf[10];

	s = 0;
	i = 0;
	if (n == 0)
		buf[i++] = 0 + 48;
	while (n)
	{
		buf[i++] = n % 10 + 48;
		n /= 10;
	}
	i--;
	while (i >= 0)
		str[s++] = buf[i--];
	str[s] = 0;
}

char	*ft_itoa_un(unsigned int n)
{
	int		len;
	char	*str;

	len = check_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	input_str(str, n);
	return (str);
}
