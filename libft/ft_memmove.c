/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:23:06 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 11:55:50 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	const char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (sr < ds)
	{
		while (len--)
		{
			ds[len] = sr[len];
		}
	}
	else
		ft_memcpy(ds, sr, len);
	return ((void*)ds);
}
