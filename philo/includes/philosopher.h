/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:50:00 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/12 00:00:04 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_status
{
	int		philo_num;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	int		max_eat;
}				t_status;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	lunch;
	pthread_mutex_t	*print;
	t_status		*status;
	int				philo_index;
	int				*stat;
	int				eat_count;
	long			last_meal;
	struct timeval	ts;
}				t_philo;

unsigned long	get_ts(struct timeval ts);
int				get_time(void);
void			ft_sleep(int ms);

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				check_args_validity(const char *str);
int				parse_arg(t_status *status, int argc, char **argv);

pthread_mutex_t	*init_fork(t_status *status);
void			get_fork(t_philo *philo, int i, pthread_mutex_t *fork, \
	int philo_num);
void			set_philo(t_philo *philo, t_status *status, pthread_mutex_t *fork, \
	pthread_mutex_t *print);

int				take_fork(t_philo *philo, pthread_mutex_t *l_fork, \
	pthread_mutex_t *r_fork);
void			*life(void	*tmp_philo);
int				check_death(t_philo *philo, int philo_num);
int				monitering(t_status *status, t_philo *philo, int philo_num, \
	pthread_mutex_t *fork);

int				do_eat(t_philo *philo);
int				do_sleep(t_philo *philo);
int				is_dead(t_philo *philo);
void			unlock_fork(pthread_mutex_t *fork, int	philo_num);

#endif