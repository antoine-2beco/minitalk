/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:19:12 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/08 18:09:39 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while ((i < len) && (str[i] != '\0'))
	{
		k = i;
		while (needle[j] != '\0' && (k < len) && (str[k] == needle[j]))
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
