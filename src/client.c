/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/04/09 11:39:50 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	error(char *error_msg)
{
	ft_printf("Error\n%s\n", error_msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		error("Arguments Error");
	argv++;
	return (0);
}
