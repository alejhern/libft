/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:38:48 by alejhern          #+#    #+#             */
/*   Updated: 2025/03/30 01:18:33 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	**tmp_paths;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = ft_split(ft_getenv("PATH", env) + 5, ':');
	if (!paths)
		ft_error_exit("malloc err");
	tmp_paths = paths;
	path = ft_strdup(cmd);
	while (*tmp_paths)
	{
		free(path);
		path = ft_strjoin(*tmp_paths++, "/");
		if (!path)
			break ;
		path = ft_strappend(path, cmd);
		if (path && access(path, X_OK) == 0)
			break ;
	}
	ft_free_array((void ***)&paths);
	return (path);
}

static int	comand_not_found(char **cmd, char *path)
{
	ft_putstr_fd("comand not found: ", 2);
	if (cmd)
	{
		ft_putendl_fd(cmd[0], 2);
		ft_free_array((void ***)&cmd);
	}
	free(path);
	return (127);
}

static int	manage_pid(char **cmd, char *path, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		ft_free_array((void ***)&cmd);
		free(path);
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(path, cmd, env) == -1)
		{
			perror("Cannot execute command");
			exit(126);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}

int	ft_execute(char **cmd, char **env)
{
	char	*path;
	int		pid_wait;

	if (cmd == NULL || cmd[0] == NULL)
		comand_not_found(NULL, NULL);
	path = find_path(cmd[0], env);
	if (!path || access(path, X_OK) == -1)
		return (comand_not_found(cmd, path));
	pid_wait = manage_pid(cmd, path, env);
	free(path);
	if (pid_wait)
		return (1);
	return (0);
}
