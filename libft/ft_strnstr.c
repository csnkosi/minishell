/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:35:20 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 16:48:49 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen((char*)little) == 0)
		return ((char*)big);
	if (ft_strlen((char*)big) == 0)
		return (NULL);
	while (big[i] && len > i)
	{
		j = 0;
		while (big[i] == little[j] && big[i] && little[j] && len > i)
		{
			i++;
			j++;
			if (j == ft_strlen((char*)little))
				return ((char*)&big[i - ft_strlen((char*)little)]);
		}
		if (j == 0)
			i++;
	}
	return (NULL);
}
