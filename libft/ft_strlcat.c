/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:30:32 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 14:37:34 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	dstlen = i;
	if ((size - i) == 0)
		return (srclen + i);
	while (src[i - dstlen] && i < size - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < size)
		dst[i] = '\0';
	return (dstlen + srclen);
}
