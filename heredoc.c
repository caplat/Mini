/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:40:20 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/16 12:20:38 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	too_much_bis(int fd)
{
	close(fd);
	exit(1);
}

static int	too_much(int fd, char *del)
{
	char	*buffer;

	while (1)
	{
		buffer = readline(">");
		if (!buffer)
		{
			perror("readline error");
			too_much_bis(fd);
		}
		if (ft_strncmp(buffer, del, ft_strlen(del) + 1) == 0)
		{
			safe_free(&buffer);
			return (1);
		}
		if (write(fd, buffer, ft_strlen(buffer)) == -1)
		{
			perror("write error");
			safe_free(&buffer);
			too_much_bis(fd);
		}
		write(fd, "\n", 1);
		safe_free(&buffer);
	}
	return (0);
}

void here_doc(t_mini *shell, char ***tab)
{
	int fd;
	int i;
	int j;
	char *del;

	i = -1;
	j = -1;
	del = NULL;
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if(fd == -1)
	{
		perror("open error");
		free_shell(shell);
		exit(1);
	}
	while(tab[++i])
	{	
		while(tab[i][++j])
		{
			check_flag(tab[i][j],shell,i);
			if(ft_strncmp(tab[i][j],"<<",3) == 0 && tab[i][j + 1]
				&& shell->flag == 0)
			{
				del = ft_strdup(tab[i][j + 1]);
				printf("del-->%s\n",del);
				if(too_much(fd,del) == 1)
					break;
				safe_free(&del);
			}
		}
		j = 0;
	}
	safe_free(&del);
	close(fd);
}
void erase(char ***tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(tab[++i])
	{
		while(tab[i][++j])
		{
			if(ft_strncmp(tab[i][j],"<<",3) == 0 && tab[i][j + 1])
		}
	}
}