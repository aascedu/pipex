/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:59:32 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/25 13:57:18 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	index_first_cmd(t_pipex *data)
{
	if (ft_strncmp(data->av[1], "here_doc", ft_strlen(data->av[1]) == 0))
		return (3);
	return (2);
}

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
	if (data->i == index_first_cmd(data))
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
