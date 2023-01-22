/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:20:30 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/22 12:00:44 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_input(t_pipex *data, int *p_end)
{
	char	*str;

	close(p_end[0]);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (ft_strncmp(str, data->av[2], ft_strlen(str) - 1) == 0)
		{
			free(str);
			exit(0);
		}
		write(p_end[1], str, ft_strlen(str));
		free(str);
	}
}

void	here_doc(t_pipex *data)
{
	pid_t	read_proc;
	int		p_end[2];

	if (pipe(p_end) == -1)
		exit(1);
	read_proc = fork();
	if (read_proc == -1)
		exit(1);
	else if (!read_proc)
		here_doc_input(data, p_end);
	else
	{
		close(p_end[1]);
		dup2(p_end[0], STDIN_FILENO);
		wait(NULL);
	}
}
