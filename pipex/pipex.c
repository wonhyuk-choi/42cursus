/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:10:10 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/14 23:16:23 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(t_pipex *pipex)
{
	dup2(pipex->fd1, 0);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	execve(pipex->cmd1, pipex->cmd1_arg, pipex->env);
}

void	execute_cmd2(t_pipex *pipex)
{
	dup2(pipex->fd2, 1);
	dup2(pipex->fd[0], 0);
	close(pipex->fd[0]);
	execve(pipex->cmd2, pipex->cmd2_arg, pipex->env);
}

void	start_pipex(t_pipex *pipex)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error_print("Fork fail!", 1);
	else if (pid == 0)
		execute_cmd1(pipex);
	close(pipex->fd[1]);
	pid = fork();
	if (pid == 0)
		execute_cmd2(pipex);
	close(pipex->fd[0]);
	waitpid(pipex->fd[0], &(pipex->fd_status), 0);
	waitpid(pipex->fd[1], &(pipex->fd_status), 0);
}

void	pipe_check(t_pipex **pipex)
{
	if ((*pipex)->fd1 < 0)
		error_print(strerror(errno), 1);
	if ((*pipex)->fd2 < 0)
		error_print(strerror(errno), 1);
	(*pipex)->cmd1_arg = ft_split((*pipex)->cmd1, ' ');
	search_cmd_path(pipex, 1);
	(*pipex)->cmd2_arg = ft_split((*pipex)->cmd2, ' ');
	search_cmd_path(pipex, 2);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (argc == 5)
	{
		pipex = malloc(sizeof(t_pipex));
		if (pipe(pipex->fd) == -1)
			error_print("Pipe error", 1);
		pipex->fd1 = open(argv[1], O_RDONLY);
		pipex->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		pipex->env = env;
		pipex->cmd1 = argv[2];
		pipex->cmd2 = argv[3];
		pipe_check(&pipex);
		start_pipex(pipex);
		close(pipex->fd1);
		close(pipex->fd2);
	}
	else
		error_print("style : ./pipex file1 cmd1 cmd2 file2", 1);
	if (WIFEXITED(pipex->fd_status))
		return (WEXITSTATUS(pipex->fd_status));
	return (0);
}
