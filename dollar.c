/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:09 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/14 19:16:24 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_flag(char *line, t_mini *shell, int i)
{
	if (line[i] == '\"' && shell->flag == 0)
		shell->flag = 2;
	else if (line[i] == '\"' && shell->flag == 2)
		shell->flag = 0;
	else if (line[i] == '\'' && shell->flag == 0)
		shell->flag = 1;
	else if (line[i] == '\'' && shell->flag == 1)
		shell->flag = 0;
	else if (line[i] == '$')
		return ;
	i++;
}

static char	*compare_line(char *line, int i)
{
	char	*compare;
	int		length;
	int		pos;
	int		j;

	compare = NULL;
	length = 0;
	j = 0;
	i++;
	pos = i;
	while (ft_isalnum(line[i]) == 1 || line[i] == '_')
	{
		i++;
		length++;
	}
	compare = malloc(sizeof(char) * (length + 1));
	while (j < length)
	{
		compare[j] = line[pos];
		j++;
		pos++;
	}
	compare[j] = 0;
	return (compare);
}

static int	compare_with_env(char *compare, t_mini *shell)
{
	int	i;
	int length_command;

	i = 0;
	while (shell->env[i])
	{
		shell->command = ft_split(shell->env[i], '=');
		length_command = ft_strlen(shell->command[0]);
		if (ft_strncmp(compare, shell->command[0], length_command
				+ 1) == 0)
			return (1);
		else
		{
			free_arr(shell->command);
			i++;
		}
	}
	// free_arr(shell->command);
	return (0);
}

void	replace_line(char *line, t_mini *shell)
{
	char *compare;
	int i;
	int j;
	int length;

	i = -1;
	j = 0;
	length = 0;
	while (line[++i])
	{
		set_flag(line, shell, i);
		if (line[i] == '$' && (shell->flag == 0 || shell->flag == 2)
			&& (line[i + 1] != '?' && line[i + 1] != '\0'))
		{
			compare = compare_line(line, i);

			if (compare_with_env(compare, shell) == 1)
			{	
				while (shell->command[1][j])
				{
					shell->add_char = add_char(shell->add_char,
					shell->command[1][j++]);
				}
					i += ft_strlen(shell->command[0]);
					j = 0;
					free_arr(shell->command);
					// norme_dollar(&var, shell);
			}	
			else
				i += ft_strlen(compare);
			free(compare);
		}
		else
			shell->add_char = add_char(shell->add_char, line[i]);
	}
	shell->add_char = add_char(shell->add_char, '\0');

}
