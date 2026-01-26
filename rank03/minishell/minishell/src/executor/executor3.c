/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:01:14 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/26 10:01:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pipe_cleanup(int fd[], t_node *ast, int *status)
{
	close(fd[0]);
	close(fd[1]);
	signal_pipe_revert(ast);
	exec_error(status, "fork");
}

void	signal_pipe_hold(t_node *ast)
{
	ast->old_sigint = signal(SIGINT, SIG_IGN);
	ast->old_sigquit = signal(SIGQUIT, SIG_IGN);
}

void	signal_pipe_revert(t_node *ast)
{
	signal(SIGINT, ast->old_sigint);
	signal(SIGQUIT, ast->old_sigquit);
}
