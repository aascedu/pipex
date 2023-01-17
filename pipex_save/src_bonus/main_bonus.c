/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:41 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/17 11:31:40 by aascedu          ###   ########lyon.fr   */
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
		dup2(p_end[1], 1);
		do_cmd(data);
	}
	else
	{
		close(p_end[1]);
		dup2(p_end[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.ac = argc;
	data.av = argv;
	data.envp = envp;
	malloc_fd(&data);
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
		data.i = 1;
	}
	while (++data.i < data.ac - 1)
		pipex(&data);
	close_fd
	return (0);
}
