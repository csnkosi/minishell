/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:38:19 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/22 12:04:07 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*ret;
	char	*str;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	else
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		str = ft_strcpy(str, str + i);
		i = ft_strlen(str) - 1;
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && i >= 0)
		{
			str[i] = '\0';
			i--;
		}
		ret = ft_strdup(str);
		free(str);
		return (ret);
	}
}
