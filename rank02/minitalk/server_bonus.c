/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:23 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/13 12:49:24 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	bit_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;

	(void)context;
	if (signum == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(2, "Error: Failed to send ACK to client\n", 36);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = bit_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: sigaction failed for SIGUSR1\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: sigaction failed for SIGUSR2\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
