/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:07:24 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/15 16:43:30 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *ret, char *backup, size_t size);
size_t	ft_strlcat(char *str1, char *str2, size_t size);
char	*ft_strjoin(char *backup, char *buff);
int		ft_is_endet(char *backup);
int		ft_split_line(char **backup, char **line, int check);
int		ft_end(char **backup, char **line);
int		get_next_line(int fd, char **line);

#endif
