/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:30:39 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/15 14:59:39 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	frame->argv = (char *const *)tmp;
}

static void	cmd_run(char *argv)
{
	int	i;
	t_cmd	frame;

	i = 0;
	cmd_init(argv, &frame);
	while (i < 5)
		execve(frame.cmd[i++], frame.argv, NULL);
	perror(frame.argv[0]);
}

int	main(int argc, char **argv)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipe_fd) == -1)
		return (error_write("pipe fail"));
	if (pid = fork() < 0)
		return (error_write("fork fail"));
	while (argc - 2 > 0)
	{
		if (pid > 0)
		{
			if (waitpid(pid, &status, 0) == 0)
				return (error_write("waitpid error"));
			pipe_connect(pipe_fd, 1);
		}
		else if (pid == 0)
		{
		
		}
		argc--;
	}
	return (0);
}