/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:56:02 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/22 12:40:49 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ctop(const char *s, char c)
{
	int		ct;
	int		sbstr;

	sbstr = 0;
	ct = 0;
	while (*s != '\0')
	{
		if (sbstr == 1 && *s == c)
			sbstr = 0;
		if (sbstr == 0 && *s != c)
		{
			sbstr = 1;
			ct++;
		}
		s++;
	}
	return (ct);
}

static	int	ft_lenw(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		wrd;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	wrd = ft_ctop((const char *)s, c);
	splt = (char **)malloc(sizeof(*splt) * (ft_ctop((const char *)s, c) + 1));
	if (splt == NULL)
		return (NULL);
	while (wrd--)
	{
		while (*s == c && *s != '\0')
			s++;
		splt[i] = ft_strsub((const char *)s, 0, ft_lenw((const char *)s, c));
		if (splt[i] == NULL)
			return (NULL);
		s = s + ft_lenw(s, c);
		i++;
	}
	splt[i] = NULL;
	return (splt);
}
