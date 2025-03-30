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
	while (ft_strnstr(*env, "PATH", 4) == 0)
		env++;
	paths = ft_split(*env + 5, ':');
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

static void	comand_not_found(char **cmd, char *path)
{
	ft_putstr_fd("comand not found: ", 2);
	if (cmd)
	{
		ft_putendl_fd(cmd[0], 2);
		ft_free_array((void ***)&cmd);
	}
	free(path);
	exit(127);
}

void	ft_execute(char *line, char **env)
{
	char	**cmd;
	char	*path;
	int		resp;

	if (!line || *line == '\0')
		comand_not_found(NULL, NULL);
	cmd = ft_split(line, ' ');
	if (!cmd)
		ft_error_exit("Cannot allocate memory");
	path = find_path(cmd[0], env);
	if (!path || access(path, X_OK) == -1)
		comand_not_found(cmd, path);
	resp = execve(path, cmd, env);
	ft_free_array((void ***)&cmd);
	free(path);
	if (resp == -1)
	{
		perror("Cannot execute command");
		exit(126);
	}
}
