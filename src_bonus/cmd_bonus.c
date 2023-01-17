/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:37:00 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/17 11:26:42 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*find_path(char **envp)
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

static char	*get_path(t_pipex *data)
{
	int		i;
	char	*try_path;
	char	*try_cmd;
	char	*total_path;
	char	**path_splitted;

	if (access(data->av[data->i], F_OK | X_OK) == 0)
		return (data->av[data->i]);
	total_path = find_path(data->envp);
	path_splitted = ft_split(total_path + 5, ':');
	i = 0;
	while (path_splitted[i])
	{
		try_path = ft_strjoin(path_splitted[i], "/");
		try_cmd = ft_strjoin(try_path, data->av[data->i]);
		if (access(try_cmd, F_OK | X_OK) == 0)
			return (free(try_path), free_tab(path_splitted), try_cmd);
		free(try_cmd);
		free(try_path);
		i++;
	}
	return (free_tab(path_splitted), NULL);
}

void	do_cmd(t_pipex *data)
{
	char	*path;
	char	**cmd_splitted;

	cmd_splitted = ft_split(data->av[data->i], ' ');
	path = get_path(data);
	if (execve(path, cmd_splitted, data->envp) == 0)
	{
	free(path);
	free_tab(cmd_splitted);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
	}
}
