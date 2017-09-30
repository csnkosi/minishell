/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:48:30 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/22 11:44:57 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char*)ft_memalloc((sizeof(char) * len1 + len2) + 1);
	if (s1 && s2 && str)
	{
		while (i < len1)
		{
			str[i] = *s1++;
			i++;
		}
		while (i < len1 + len2)
		{
			str[i] = *s2++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
