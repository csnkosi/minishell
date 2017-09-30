/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:43:42 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/11 13:34:15 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	j;

	len = ft_len(n);
	j = n;
	if (n < 0)
	{
		j = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = j % 10 + '0';
	while (j /= 10)
		s[--len] = j % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
