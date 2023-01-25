/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:35:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/25 16:49:15 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	pipex(t_pipex *data)
// {
// 	int		p_end[2];
// 	pid_t	pid;

// 	if (data->i == data->ac - 2)
// 		dup2(data->fd_exit, STDOUT_FILENO);
// 	else if (pipe(p_end) == -1)
// 		exit(0);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);
// 	if (!pid)
// 	{
// 		if (data->i != data->ac - 2)
// 		{
// 			close(p_end[0]);
// 			dup2(p_end[1], STDOUT_FILENO);
// 		}
// 		do_cmd(data);
// 	}
// 	else if (pid && data->i != data->ac - 2)
// 	{
// 		close(p_end[1]);
// 		dup2(p_end[0], STDIN_FILENO);
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	init_data(&data, argc, argv, envp);
	if (data.ac < 5)
		wrong_arg("too_few");
	if (data.ac > 5)
		wrong_arg("too_many");
	my_open(&data, "OPEN");
	my_open(&data, "CLOSE");
	dup2(data.fd_entry, STDIN_FILENO);
	data.i = 1;
	while (++data.i < data.ac - 1)
		pipex(&data);
	while (data.i-- > 0)
		wait(NULL);
	return (restore_std(&data), 0);
}
