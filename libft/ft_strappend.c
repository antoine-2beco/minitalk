/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:03:34 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 15:44:45 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;
	int		n;

	if (!*s1 || !s2)
		return (NULL);
	n = ft_strlen(*s1) + ft_strlen(s2) + 1;
	str = ft_calloc(n, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, n);
	free(*s1);
	return (str);
}
