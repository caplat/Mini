/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:37:29 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 11:58:58 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

int			g_error_code;

typedef struct s_mini
{
	char	*line;
	char	**env;
	char	**command;
	int		flag;
	char	*add_char;
	char ***big_tab;
	int stdin_cpy;
	int stdout_cpy;

}			t_mini;

// Signal

void		do_signal(void);

// Parsing

int			count_quotes(char *line, t_mini *shell);

//Utils

void		initialize(char **env, t_mini *shell);
char		*add_char(char *str, char c);
int			find_length(char **str);
void		print_tab(char **tab);
void		check_flag(char *line, t_mini *shell, int i);

//Utils_bis

void print_b_tab(char ***tab);
void free_big_tab(char ***tab);
void remove_str_from_tab(char ***tab, int position);
int find_position(char ***tab, char *element_to_find); 

//Free

void		free_shell(t_mini *shell);
void		free_arr(char **arr);
void		safe_free(char **str);

// Dollar

void		replace_line(char *line, t_mini *shell);

// Triple

void		replace_char(char *str, char target, char replacement,
				t_mini *shell);
void big_tab(t_mini *shell, char *str);

// Here_doc

void here_doc(t_mini *shell, char ***tab);
void erase(char ***tab);

#endif