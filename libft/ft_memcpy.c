/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:56:21 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 11:35:14 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sc;
	char	*dt;

	i = 0;
	sc = (char *)src;
	dt = (char *)dst;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		dt[i] = sc[i];
		i++;
	}
	return ((void*)dt);
}
