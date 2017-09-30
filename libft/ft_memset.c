/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:53:38 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 11:10:20 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ret;

	if ((int)len < 0)
		return (NULL);
	i = 0;
	ret = (unsigned char *)b;
	while (len > 0)
	{
		ret[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (ret);
}
