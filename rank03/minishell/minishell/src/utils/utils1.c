/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:01:59 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/26 10:02:03 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	append_token(t_token **list, t_token *new_token)
{
	t_token	*current;

	if (!*list)
		*list = new_token;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = new_token;
		new_token->next = NULL;
	}
}

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->value)
			free(head->value);
		free(head);
		head = tmp;
	}
}

void	free_fds(t_fd *head)
{
	t_fd	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->value)
			free(head->value);
		free(head);
		head = tmp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_tokens(cmd->argv);
	free_fds(cmd->fds);
	free_fds(cmd->heredoc_delimiter);
	if (cmd->heredoc_fd != -1)
		close(cmd->heredoc_fd);
	if (cmd->fd_in != 0 && cmd->fd_in != -1)
		close(cmd->fd_in);
	if (cmd->fd_out != 1 && cmd->fd_out != -1)
		close(cmd->fd_out);
	free(cmd);
}

void	free_node(t_node *node)
{
	if (!node)
		return ;
	if (node->cmd)
		free_cmd(node->cmd);
	if (node->lhs)
		free_node(node->lhs);
	if (node->rhs)
		free_node(node->rhs);
	free(node);
}
