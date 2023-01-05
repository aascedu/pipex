/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:29:09 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/05 15:01:18 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_splitted;

	cmd_splitted = ft_split(cmd, ' ');
	path = get_path(cmd_splitted[0], envp);
	execve(path, cmd_splitted, envp);
	free(path);
	free_tab(cmd_splitted);
	ft_putstr_fd(strerror(errno), 2);
}

void	child_process(char **argv, char **envp, int *p_end)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		exit(1);
	}
	dup2(fd, 0);
	if (dup2(fd, 0) == -1)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	dup2(p_end[1], 1);
	if (dup2(p_end[1], 1) == -1)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	close(p_end[0]);
	do_cmd(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *p_end)
{
	int	fd;

	fd = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		exit(1);
	}
	dup2(fd, 1);
	if (dup2(fd, 1) == -1)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	dup2(p_end[0], 0);
	if (dup2(p_end[0], 0) == -1)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	close(p_end[1]);
	do_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_end[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler();
	if (pipe(p_end) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (!pid)
		child_process(argv, envp, p_end);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, p_end);
}
