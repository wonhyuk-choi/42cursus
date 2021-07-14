/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:07:47 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/14 22:36:28 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_new_path(char **env)
{
	int		i;
	char	*new_path;

	i = 0;
	new_path = NULL;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
		{
			new_path = ft_strdup(ft_strrchr(env[i], '=') + 1);
			break ;
		}
		i++;
	}
	return (new_path);
}

int	path_connect(char *path, char **cmd_flag, char *arg)
{
	char	*cmd;
	char	*tmp;

	cmd = ft_strjoin(path, "/");
	tmp = cmd;
	cmd = ft_strjoin(cmd, arg);
	free(tmp);
	if (open(cmd, O_RDONLY) > 0)
	{
		*cmd_flag = ft_strdup(cmd);
		free(cmd);
		return (1);
	}
	free(cmd);
	return (0);
}

void	search_cmd_path(t_pipex **pipex, int cmd_flag)
{
	int		i;
	int		check;
	char	*new_path;
	char	**split_path;

	check = 0;
	i = 0;
	new_path = get_new_path((*pipex)->env);
	split_path = ft_split(new_path, ':');
	while (split_path[i] && !check)
	{
		if (cmd_flag == 1)
			check = path_connect(split_path[i++], &(*pipex)->cmd1, \
				(*pipex)->cmd1_arg[0]);
		else if (cmd_flag == 2)
			check = path_connect(split_path[i++], &(*pipex)->cmd2, \
				(*pipex)->cmd2_arg[0]);
	}
	free(new_path);
	i = 0;
	while (split_path[i])
		free(split_path[i++]);
	free(split_path);
	if (!check)
		error_print("Command not found", 1);
}
