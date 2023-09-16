/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:56 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 12:03:50 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell_loop(t_mini *shell)
{
	while(1)
	{
		shell->line = readline(">>");
		if (shell->line)
		{
			if (ft_strlen(shell->line) > 0)
				add_history(shell->line);
			if(count_quotes(shell->line, shell) == 1)
			{
				shell->add_char = ft_calloc(1,2);
				replace_line(shell->line, shell);
				// printf("add_char -->%s\n",shell->add_char);
				replace_char(shell->add_char,' ', '#', shell);
				// printf("add_char -->%s\n",shell->add_char);
				big_tab(shell,shell->add_char);
				// here_doc(shell,shell->big_tab);
				erase(shell->big_tab);
			}
			dup2(shell->stdout_cpy, STDOUT_FILENO);
			dup2(shell->stdin_cpy, STDIN_FILENO);
			free_shell(shell);
		}
		else
		{
			exit(0);
		}
	}
}

int main(int argc,char **argv,char **env)
{
	t_mini shell;
	
	(void) argv;
	g_error_code = 0;
	if (argc != 1)
	{
		printf("retry without arguments\n");
		exit(0);
	}
	initialize(env,&shell);
	rl_catch_signals = 0;
	do_signal();
	minishell_loop(&shell);
}