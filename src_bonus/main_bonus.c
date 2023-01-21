/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:41 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/21 15:15:28 by aascedu          ###   ########lyon.fr   */
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
		close(p_end[0]);
		dup2(p_end[1], STDOUT_FILENO);
		// close(p_end[1]);
		do_cmd(data);
	}
	else
	{
		close(p_end[1]);
		dup2(p_end[0], STDIN_FILENO);
		// close(p_end[0]);
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
		// if (argc > 6)
		// 	wrong_arg("too_many");
		// i = 2;
		// data->fd_exit = my_open(data, "DOC");
		// here_doc(data);
		exit(1);
	}
	else
	{
		data.fd_entry = my_open(&data, "OPEN");
		data.fd_exit = my_open(&data, "CLOSE");
		dup2(data.fd_entry, STDIN_FILENO);
		data.i = 1;
	}
	while (++data.i < data.ac - 1)
		pipex(&data);
	dup2(data.fd_exit, STDOUT_FILENO);
	do_cmd(&data);
	wait(NULL);
	return (0);
}
