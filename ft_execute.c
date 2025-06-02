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
	ft_putstr_fd("comand not found: ", STDERR_FILENO);
	if (cmd)
		ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	free(path);
	return (127);
}

static int	manage_pid(char **cmd, char *path, char **env, int make_fork)
{
	pid_t	pid;
	int		status;

	pid = 0;
	if (make_fork)
		pid = fork();
	if (pid == -1)
		return (perror("fork failed"), ft_free_array((void ***)&cmd),
			free(path), 0);
	else if (pid == 0)
	{
		if (execve(path, cmd, env) == -1)
		{
			ft_putendl_fd("Cannot execute command", STDERR_FILENO);
			if (make_fork)
				return (0);
			exit(126);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}

int	ft_execute(char **cmd, char **env, int make_fork)
{
	char	*path;
	int		pid_wait;

	if (cmd == NULL || cmd[0] == NULL)
		return (comand_not_found(NULL, NULL));
	path = find_path(cmd[0], env);
	if (!path || access(path, X_OK) == -1)
		return (comand_not_found(cmd, path));
	pid_wait = manage_pid(cmd, path, env, make_fork);
	free(path);
	return (pid_wait);
}
