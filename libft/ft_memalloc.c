/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:23:52 by cnkosi            #+#    #+#             */
/*   Updated: 2017/06/08 04:10:11 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!size)
		return (NULL);
	mem = malloc(sizeof(void) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, sizeof(void) * size);
	return (mem);
}
