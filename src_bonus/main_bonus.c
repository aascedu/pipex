/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:41 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/22 11:19:02 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex(t_pipex *data)
{
	int		p_end[2];
	pid_t	pid;

	if (pipe(p_end) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		if (data->i == data->ac - 2)
			dup2(data->fd_exit, STDOUT_FILENO);
		else if (data->i != data->ac - 2)
		{
			dup2(p_end[1], STDOUT_FILENO);
			close(p_end[0]);
		}
		do_cmd(data);
	}
	else if (pid && data->i != data->ac - 2)
	{
		dup2(p_end[0], STDIN_FILENO);
		close(p_end[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	init_data(&data, argc, argv, envp);
	if (data.ac < 5)
		wrong_arg("too_few");
	if (ft_strncmp(data.av[1], "here_doc", 8) == 0)
	{
		if (data.ac > 6)
			wrong_arg("too_many");
		data.fd_exit = my_open(&data, "DOC");
		here_doc(&data);
	}
	else
	{
		data.fd_entry = my_open(&data, "OPEN");
		data.fd_exit = my_open(&data, "CLOSE");
		dup2(data.fd_entry, STDIN_FILENO);
	}
	while (++data.i < data.ac - 1)
		pipex(&data);
	while (data.i-- > 0)
		wait(NULL);
	return (restore_std(&data), 0);
}
