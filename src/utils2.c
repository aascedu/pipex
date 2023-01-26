/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:49:57 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 16:18:35 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	reset_pipe(t_pipex *data)
{
	if (data->i % 2 == 0)
	{
		close(data->p_end1[0]);
		close(data->p_end1[1]);
		if (pipe(data->p_end1) == -1)
			exit(1);
	}
	else
	{
		close(data->p_end2[0]);
		close(data->p_end2[1]);
		if (pipe(data->p_end2) == -1)
			exit(1);
	}
}

void	init_pipes(t_pipex *data)
{
	if (pipe(data->p_end1) == -1)
		exit(1);
	if (pipe(data->p_end2) == -1)
		exit(1);
}

void	my_close(t_pipex *data)
{
	close(data->p_end1[0]);
	close(data->p_end1[1]);
	close(data->p_end2[0]);
	close(data->p_end2[1]);
	close(data->fd_entry);
	close(data->fd_exit);
}

void	set_pipe(t_pipex *data)
{
	if (data->i == 2)
	{
		dup2(data->fd_entry, STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
	else if (data->i == data->ac - 2)
	{
		if (data->i % 2 != 0)
			dup2(data->p_end1[0], STDIN_FILENO);
		else
			dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->fd_exit, STDOUT_FILENO);
	}
	else if (data->i % 2 != 0)
	{
		dup2(data->p_end1[0], STDIN_FILENO);
		dup2(data->p_end2[1], STDOUT_FILENO);
	}
	else
	{
		dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
}
