
#include "libft.h"

static int  parent_pipe_process(int pipe_fd[2], int input_fd)
{
    close(pipe_fd[1]);
	if (input_fd != -1)
		close(input_fd);
	return (pipe_fd[0]);
}

static int	child_pipe_process(int input_fd, int pipe_fd[2], char **cmd,
		char **env)
{
	if (input_fd != -1)
	{
		if (dup2(input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 input");
			return (-1);
		}
		close(input_fd);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 output");
		return (-1);
	}
	close(pipe_fd[1]);
	return (ft_execute(cmd, env, 0));
}

int	ft_pipe(int input_fd, char **cmd, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		child_response;

	if (pipe(pipe_fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (0);
	}
	if (pid == 0)
	{
		close(pipe_fd[0]);
		child_response = child_pipe_process(input_fd, pipe_fd, cmd, env);
		if (child_response)
			close(pipe_fd[1]);
		return (child_response);
	}
	else
	    return (parent_pipe_process(pipe_fd, input_fd));
}
