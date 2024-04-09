/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:45:47 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/08 18:09:43 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && check_trim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && (s1[end] == '\0' || check_trim(s1[end], set)))
		end--;
	if (!(s1[0] == '\0'))
		end++;
	str = malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
