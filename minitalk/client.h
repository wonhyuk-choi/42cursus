/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 01:20:09 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/15 02:50:54 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_isdigit(int c);
int	is_num(char *str);
int	ft_atoi(const char *str);
int	check_str(char *str);

#endif