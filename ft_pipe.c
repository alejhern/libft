/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:17:08 by amhernandez       #+#    #+#             */
/*   Updated: 2025/06/09 09:17:22 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	child_pipe_process(int input_fd, int pipe_fd[2], char **cmd,
		char **env)
{
	if (input_fd != -1)
	{
		if (dup2(input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 input");
			close(input_fd);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			exit(1);
		}
		close(input_fd);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 output");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exit(ft_execute(cmd, env, NULL));
}

static int	parent_pipe_process(int pipe_fd[2], int input_fd)
{
	close(pipe_fd[1]);
	if (input_fd != -1)
		close(input_fd);
	return (pipe_fd[0]);
}

int	ft_pipe(int input_fd, char **cmd, char **env, pid_t *pid)
{
	int	pipe_fd[2];

	if (!pid)
		return (-1);
	if (pipe(pipe_fd) == -1)
		return (0);
	*pid = fork();
	if (*pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (0);
	}
	if (*pid == 0)
		child_pipe_process(input_fd, pipe_fd, cmd, env);
	return (parent_pipe_process(pipe_fd, input_fd));
}
