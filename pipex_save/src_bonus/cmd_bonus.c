/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:49 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/16 17:44:52 by arthurasced      ###   ########lyon.fr   */
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

		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
	total_path = find_path(envp);
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

void	do_cmd_b(char *cmd, char **envp)
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
