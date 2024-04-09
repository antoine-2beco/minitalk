/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/09 15:06:53 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void    send_signal(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c &(0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        bit++;
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
		send_signal(pid, argv[2][i]);
		i++;
	}
	return (0);
}
