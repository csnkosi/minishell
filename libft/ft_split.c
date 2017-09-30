/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:16:08 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/27 18:08:58 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		r_size(char *s)
{
	unsigned int	len;
	int				i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			++i;
		else
		{
			++len;
			while (s[i] && !ft_isspace(s[i]))
				++i;
		}
	}
	return (len);
}

char	**ft_split(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	char	**r;
	int		w_len = 0;

	if (!(r = (char**)malloc(sizeof(r) * (r_size(s) + 1))))
		return (NULL);
	while (s[i] && j < r_size(s))
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		while (s[i] && !ft_isspace(s[i]))
		{
			w_len++;
			i++;
		}
		if (!(r[j] = (char*)malloc(sizeof(char) * (w_len + 1))))
			return (0);
		k = 0;
		while (w_len)
			r[j][k++] = s[i - w_len--];
		r[j++][k] = '\0';
	}
	r[j] = NULL;
	return (r);
}
