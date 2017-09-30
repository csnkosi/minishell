/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 04:17:24 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/21 15:28:33 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen((char*)little) == 0)
		return ((char*)big);
	if (ft_strlen((char*)big) == 0)
		return (NULL);
	while (i < ft_strlen(big) + 1)
	{
		j = 0;
		while (little[j] == big[j + i])
		{
			if (j == ft_strlen(little) - 1)
				return ((char*)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
