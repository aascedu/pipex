/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:37:00 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 15:57:54 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		if (!str)
		{
			perror("ft_substr");
			exit(1);
		}
		if (ft_strncmp(str, "PATH", 5) == 0)
			return (free(str), envp[i]);
		free(str);
		i++;
	}
	return (NULL);
}

char	*get_path(t_pipex *data, char *cmd)
{
	int		i;
	char	*try_path;
	char	*try_cmd;
	char	*total_path;
	char	**path_splitted;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	total_path = find_path(data->envp);
	if (!total_path)
		path_error();
	path_splitted = ft_split(total_path + 5, ':');
	i = 0;
	while (path_splitted[i])
	{
		try_path = ft_strjoin(path_splitted[i], "/");
		try_cmd = ft_strjoin(try_path, cmd);
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
	path = get_path(data, cmd_splitted[0]);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", STDERR_FILENO);
		ft_putendl_fd(data->av[data->i], STDERR_FILENO);
		free_tab(cmd_splitted);
		exit(1);
	}
	if (execve(path, cmd_splitted, data->envp) == -1)
	{
		free(path);
		free_tab(cmd_splitted);
	}
}
