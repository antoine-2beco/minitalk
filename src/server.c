/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:09 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/09 12:36:44 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(void)
{
	struct	sigaction sa;
	int		pid;

	pid = getpid();
	ft_printf("PID PROCCES : %i\n", pid);
	return (0);
}
