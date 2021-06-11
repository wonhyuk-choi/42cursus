/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:10:10 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/08 17:59:22 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipe_connect(int pipe_fd[2], int io)
{
	dup2(pipe_fd[io], io);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

static void	cmd_init(const char *cmd, t_cmd *frame)
{
	char	**tmp;

	tmp = ft_split(cmd, ' ');
	frame->cmd[0] = ft_strjoin("/bin/", tmp[0]);
	frame->cmd[1] = ft_strjoin("/usr/local/bib/", tmp[0]);
	frame->cmd[2] = ft_strjoin("/usr/bin/", tmp[0]);
	frame->cmd[3] = ft_strjoin("/usr/sbin/", tmp[0]);
	frame->cmd[4] = ft_strjoin("/sbin/", tmp[0]);
	frame->argv = tmp;
	frame->envp = NULL;
}

static void	cmd_run(char *argv, t_cmd *frame)
{
	int	i;

	i = 0;
	cmd_init(argv, frame);
	while (i < 5)
	{
		execve(frame->cmd[i++], frame->argv, frame->envp);
	}
	perror(frame->argv[0]);
}

int			main(int argc, char **argv)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_cmd	frame;

	if (argc != 5)
		return (error_wrtie("style : ./pipex file1 cmd1 cmd2 file2"));
	if (pipe(pipe_fd) == -1)
		return (error_wrtie("pipe fail!"));
	if ((pid = fork()) < 0)
		return (error_wrtie("fork fail!"));
	if (pid == 0)
	{
		redirect_in_child(argv[1]);
		pipe_connect(pipe_fd, 1);
		cmd_run(argv[2], &frame);
	}
	else
	{
		redirect_in_parent(argv[4]);
		pipe_connect(pipe_fd, 0);
		cmd_run(argv[3], &frame);
	}
	return (0);
}
