/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:12:08 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 10:32:27 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_shell(t_mini *shell)
{
	free(shell->line);
	safe_free(&shell->add_char);
	free_big_tab(shell->big_tab);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	safe_free(char **str)
{
	if (str != NULL && *str != NULL)
		free(*str);
	*str = NULL;
}
