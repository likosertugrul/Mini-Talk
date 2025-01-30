/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertugrullikos <ertugrullikos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:25:29 by ertugrullik       #+#    #+#             */
/*   Updated: 2025/01/30 01:37:06 by ertugrullik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_signal(int signal)
{
	static unsigned char	x;
	static int				i;

	if (signal == SIGUSR1)
	{
		x = x | 1;
	}
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int main(void)
{
	ft_printf("Server started with PID: %d\n", getpid());
	signal(SIGUSR1, process_signal);
	signal(SIGUSR2, process_signal);
	while (1)
	{
		pause();
	}
	return (0);
}