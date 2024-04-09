/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:45 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/08 18:09:08 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	if (!dst && !src)
		return (NULL);
	i = -1;
	pdst = (char *)dst;
	psrc = (char *)src;
	if (pdst > psrc)
	{
		while ((int)(--len) >= 0)
			*(pdst + len) = *(psrc + len);
	}
	else
	{
		while (++i < len && (dst != 0 || src != 0))
			*(pdst + i) = *(psrc + i);
	}
	return (dst);
}
