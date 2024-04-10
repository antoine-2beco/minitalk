/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:09 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/10 13:38:12 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	char_bit[2];

	(void)info;
	(void)context;
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
	struct sigaction	sa;

	ft_printf("PID : %i\n", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
