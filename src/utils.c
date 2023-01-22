/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:06 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/22 12:09:48 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_arg(char *error)
{
	if (ft_strncmp(error, "too_few", 7) == 0)
		ft_putendl_fd("Too few args, see subject.", STDERR_FILENO);
	if (ft_strncmp(error, "too_many", 8) == 0)
		ft_putendl_fd("Too many args, see subject.", STDERR_FILENO);
	exit(1);
}

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

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
}

void	restore_std(t_pipex *data)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(data->stdin_fd, STDIN_FILENO);
	dup2(data->stdout_fd, STDOUT_FILENO);
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
