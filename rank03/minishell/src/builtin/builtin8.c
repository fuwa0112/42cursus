/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:00:55 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/26 10:00:56 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*concat_strings(const char *s1, const char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	i = -1;
	while (++i < len2)
		result[len1 + i] = s2[i];
	result[len1 + len2] = '\0';
	return (result);
}
