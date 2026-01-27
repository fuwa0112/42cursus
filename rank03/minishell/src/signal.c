/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:02:51 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/26 10:02:52 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setup_signal_handlers(void)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = handle_interactive_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_interactive_sigint(int sig)
{
	(void)sig;
	g_status = 2;
	rl_on_new_line();
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	reset_default_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	heredoc_int_handler(int sig)
{
	int	devnull;

	(void)sig;
	g_status = 2;
	devnull = open("/dev/null", O_RDONLY);
	if (devnull >= 0)
		dup2(devnull, STDIN_FILENO);
	close(devnull);
}

void	reset_heredoc_signal(void)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = heredoc_int_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	signal(SIGQUIT, SIG_IGN);
}
