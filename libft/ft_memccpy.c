/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:06:33 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 11:40:09 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
