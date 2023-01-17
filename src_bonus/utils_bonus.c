/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:37:35 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/17 15:09:22 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_fd(int **p_fd, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(p_fd[i]);
		i++;
	}
	free(p_fd);
}

void	malloc_fd(t_pipex *data)
{
	int	i;

	i = -1;
	if (ft_strncmp(data->av[1], "here_doc", 8) == 0)
		data->size = data->ac - 4;
	else
		data->size = data->ac - 3;
	data->p_fd = malloc(sizeof(int *) * (data->size));
	if (!data->p_fd)
		return ;
	while (++i <= data->size)
	{
		data->p_fd[i] = malloc(sizeof(int) * 2);
		if (!data->p_fd[i])
			return (free_fd(data->p_fd, i));
	}
}

void	close_fd(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		close(data->p_fd[i][0]);
		close(data->p_fd[i][1]);
		i++;
	}
	close(data->fd_entry);
	close(data->fd_exit);
}

int	my_open(t_pipex *data, char *rule)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(rule, "DOC", 3) == 0)
		fd = open(data->av[data->ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (ft_strncmp(rule, "OPEN", 4) == 0)
		fd = open(data->av[1], O_RDONLY);
	else if (ft_strncmp(rule, "CLOSE", 5) == 0)
		fd = open(data->av[data->ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd <= 0)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		exit(-1);
	}
	return (fd);
}
