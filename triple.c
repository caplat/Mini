/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:41:26 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 10:37:13 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_char(char *str, char target, char replacement, t_mini *shell)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		check_flag(str, shell, i);
		if (str[i] == target && shell->flag == 0)
			str[i] = replacement;
		i++;
	}
}


static int find_nb_command(t_mini *shell, char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while(str[i])
	{
		check_flag(str,shell,i);
		if(str[i] == '|' && shell->flag == 0)
		{	
			j++;
			while(str[i] && str[i] == '|')
				i++;
		}
		i++;
	}
	return(j);
}

void big_tab(t_mini *shell, char *str)
{
	int nb;
	int i;
	int j;
	char *command;
	char **tab;

	i = -1;
	j = -1;
	command = ft_calloc(1,1);
	nb = find_nb_command(shell,str);
	shell->big_tab = ft_calloc(sizeof(char **),nb + 1);
	// printf("%d\n",nb);
	while(str[++i])
	{
		check_flag(str,shell,i);
		// printf("command -->%s\n",command);
		if((str[i] && (str[i] == '|' && shell->flag == 0)))
		{
			// printf("%c\n",str[i]);
			// printf("command -->%s\n",command);
			i++;
			if(str[i] == '|')
				while(str[i] == '|')
					i++;
			tab = ft_split(command,'#');
			shell->big_tab[++j] = tab;
			free(command);
			command = ft_calloc(1,1);
		}
		command = add_char(command,shell->add_char[i]);
	}
	tab = ft_split(command,'#');
	shell->big_tab[++j] = tab;
	free(command);
	print_b_tab(shell->big_tab);
}

