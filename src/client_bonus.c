/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/10 14:41:35 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client_bonus.h"

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if (temp_c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

void	get_back(int signal, siginfo_t *info, void *context)
{
	(void)signal;
	(void)info;
	(void)context;
	ft_printf("Message has been received by %i !\n", info->si_pid);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		exit(EXIT_FAILURE);
	i = 0;
	pid = atoi(argv[1]);
	sa.sa_sigaction = get_back;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	while (argv[2][i])
	{
		send_signal(pid, (unsigned char)(argv[2][i]));
		i++;
	}
	send_signal(pid, (unsigned char)('\0'));
	while (1)
		pause();
	return (0);
}
