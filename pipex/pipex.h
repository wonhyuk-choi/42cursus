/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:10:05 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/14 23:13:57 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <string.h>

typedef struct s_pipex
{
	int		fd1;
	int		fd2;
	int		fd[2];
	int		fd_status;
	char	*cmd1;
	char	*cmd2;
	char	**env;
	char	**cmd1_arg;
	char	**cmd2_arg;
}				t_pipex;

int		ft_strlen(char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split(char const *s, char c);

void	error_print(char *str, int err);

char	*get_new_path(char **env);
int		path_connect(char *path, char **cmd_flag, char *arg);
void	search_cmd_path(t_pipex **pipex, int cmd_flag);

#endif
