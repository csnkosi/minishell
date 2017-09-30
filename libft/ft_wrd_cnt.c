/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrd_cnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:13:30 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/18 10:13:54 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrd_cnt(char *s)
{
    int	    i;
    int	    len;
    int	    w_cnt;

    i = 0;
    while (ft_isspace(s[i]))
	i++;
    len = ft_strlen(s);
    while (ft_isspace(s[len - 1]))
	len--;
    w_cnt = 1;
    while (i++ < len)
	if (ft_isspace(s[i]))
	    w_cnt++;
    return (w_cnt);
}
