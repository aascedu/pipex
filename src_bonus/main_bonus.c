/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:59:38 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/05 19:06:58 by arthurasced      ###   ########lyon.fr   */
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
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_entry;
	int	fd_exit;
		
	if (argc < 5)
	{
		ft_putstr_fd("./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc > 6)
			wrong_arg();
		i = 3;
		fd_exit = open_here_doc(argc, argv);
		here_doc(argv, envp);
	}
}