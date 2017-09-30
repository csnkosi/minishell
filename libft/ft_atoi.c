/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:19:45 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/24 13:28:22 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		i;
	int		n;
	int		ret;
	int		sign;

	i = 0;
	n = 0;
	ret = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = (ret * 10) + (int)(s[i] - '0');
		n++;
		i++;
	}
	if (n > 19)
		return ((sign < 0) ? 0 : -1);
	return (ret * sign);
}
