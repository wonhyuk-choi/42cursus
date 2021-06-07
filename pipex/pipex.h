/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:10:05 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/07 17:39:14 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_cmd
{
	const char		**cmd;
	char* const		*argv;
	char* const		*envp;
}				t_cmd;

int				error_wrtie(char *str);
int				show_error(char *str);
void			redirect_in_child(char *file);
void			redirect_in_parent(char *file);

#endif
