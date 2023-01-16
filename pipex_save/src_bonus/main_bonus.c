/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:59:38 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/16 17:48:40 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex(char *cmd, char **envp)
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
		do_cmd_b(cmd, envp);
	}
	else
	{
		close(p_end[1]);
		dup2(p_end[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_entry;
	int	fd_exit;

	if (argc < 5)
		wrong_arg_b("too_few");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		// if (argc > 6)
		// 	wrong_arg("too_many");
		// i = 3;
		// fd_exit = my_open(argc, argv, "DOC");
		// here_doc(argv, envp);
		exit(1);
	}
	else
	{
		fd_entry = my_open(argc, argv, "OPEN");
		fd_exit = my_open(argc, argv, "CLOSE");
		dup2(fd_entry, 0);
		i = 2;
	}
	while (i < argc - 2)
		pipex(argv[i++], envp);
	dup2(fd_exit, 1);
	do_cmd_b(argv[argc - 2], envp);
}
