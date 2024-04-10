/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/10 12:30:20 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

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

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	if (argc != 3)
		exit(EXIT_FAILURE);
	i = 0;
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, (unsigned char)(argv[2][i]));
		i++;
	}
	return (0);
}
