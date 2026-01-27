/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:01:37 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/26 10:01:38 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_signal_hold(t_cmd *cmd)
{
	cmd->old_sigint = signal(SIGINT, SIG_IGN);
	cmd->old_sigquit = signal(SIGQUIT, SIG_IGN);
}

void	heredoc_signal_revert(t_cmd *cmd)
{
	signal(SIGINT, cmd->old_sigint);
	signal(SIGQUIT, cmd->old_sigquit);
}
