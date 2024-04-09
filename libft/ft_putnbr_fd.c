/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:47:43 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/08 18:09:15 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		str[13];
	long		nb;
	int			i;
	int			neg;

	nb = n;
	i = 11;
	str[12] = '\0';
	neg = 0;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		neg = -1;
		nb *= -1;
	}
	while (nb != 0)
	{
		str[i--] = (char)(nb % 10) + '0';
		nb /= 10;
	}
	if (neg < 0)
		str[i--] = '-';
	ft_putstr_fd((char *)(str + (++i)), fd);
}
