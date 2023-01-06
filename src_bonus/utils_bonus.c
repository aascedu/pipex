/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:39 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/06 16:17:51 by aascedu          ###   ########lyon.fr   */
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

void	wrong_arg(int error)
{
	if (error == 1)
	{
		ft_putendl_fd("./pipex infile cmd1 cmd2...cmdn outfile", STDERR_FILENO);
		ft_putendl_fd("Or like this  :", STDERR_FILENO);
		ft_putendl_fd("./pipex here_doc LIMITER cmd cmd1 file", STDERR_FILENO);
	}
	else if (error == 2)
	{
		ft_putendl_fd("./pipex here_doc LIMITER cmd cmd1 file", STDERR_FILENO);
	}
	exit(1);
}

int	my_open(int argc, char **argv, int type)
{
	int	fd;

	if (type == 0)
	{
		fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(-1);
		}
	}
	else if (type == 1)
	{
		fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(-1);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			return (50000);
		}
	}
	return (fd);
}

char	*find_path(char **envp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		str = ft_substr(envp[i], 0, j);
		if (ft_strncmp(str, "PATH", 5) == 0)
			return (free(str), envp[i]);
		free(str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*try_path;
	char	*try_cmd;
	char	*total_path;
	char	**path_splitted;

	total_path = find_path(envp);
	path_splitted = ft_split(total_path + 5, ':');
	i = 0;
	while (path_splitted[i])
	{
		try_path = ft_strjoin(path_splitted[i], "/");
		try_cmd = ft_strjoin(try_path, cmd);
		if (access(try_cmd, F_OK | X_OK) == 0)
		{
			return (free(try_path), free_tab(path_splitted), try_cmd);
		}
		free(try_cmd);
		free(try_path);
		i++;
	}
	return (free_tab(path_splitted), NULL);
}
