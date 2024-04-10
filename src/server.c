/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:09 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/10 13:02:46 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	sig_handler(int signal)
{
	static unsigned char	char_bit[2];

	if (!char_bit[1])
		char_bit[1] = '0';
	char_bit[0] |= (signal == SIGUSR1);
	char_bit[1]++;
	if (char_bit[1] == '8')
	{
		ft_printf("%c", char_bit[0]);
		char_bit[1] = '0';
		char_bit[0] = 0;
	}
	else
		char_bit[0] <<= 1;
}

int	main(void)
{
	int					pid;

	pid = getpid();
	ft_printf("PID : %i\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
