/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:01 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/13 12:49:03 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int	g_ack = 0;

static void	ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

static void	send_char_as_bits(pid_t server_pid, unsigned char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		g_ack = 0;
		if ((c >> bit_index) & 1)
		{
			kill(server_pid, SIGUSR1);
			while (!g_ack)
				usleep(200);
		}
		else
		{
			kill(server_pid, SIGUSR2);
			while (!g_ack)
				usleep(200);
		}
		bit_index++;
	}
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <Server_PID> <Message>\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	message = argv[2];
	i = 0;
	while (message[i] != '\0')
	{
		send_char_as_bits(server_pid, message[i]);
		i++;
	}
	send_char_as_bits(server_pid, '\0');
	ft_printf("Message successfully sent.\n");
	return (0);
}
