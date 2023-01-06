/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:59:38 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/06 16:20:50 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_splitted;

	cmd_splitted = ft_split(cmd, ' ');
	path = get_path(cmd_splitted[0], envp);
	execve(path, cmd_splitted, envp);
	free(path);
	free_tab(cmd_splitted);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	multiple_pipe(char *cmd, char **envp)
{
	int		p_end[2];
	pid_t	pid;

	if (pipe(p_end) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (!pid)
	{
		close(p_end[0]);
		if (dup2(p_end[1], 1) == -1)
			error_display();
		do_cmd(cmd, envp);
	}
	else
	{
		close(p_end[1]);
		if (dup2(p_end[0], 0) == -1)
			error_display();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_entry;
	int	fd_exit;

	i = 0;
	if (argc < 5)
		wrong_arg(1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc > 6)
			wrong_arg(2);
		fd_entry = my_open(argc, argv, 0);
		i = 3;
	}
	else
	{
		fd_entry = my_open(argc, argv, 2);
		fd_exit = my_open(argc, argv, 1);
		i = 2;
	}
	if (dup2(fd_entry, 0) == -1)
		error_display();
	while (i < argc - 2)
		multiple_pipe(argv[i++], envp);
	if (dup2(fd_exit, 1) == -1)
		error_display();
	do_cmd(argv[argc - 2], envp);
}
