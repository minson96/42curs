/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:57 by minson            #+#    #+#             */
/*   Updated: 2023/06/06 14:08:14 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	min_max_check(long tot_res, int sign)
{
	if (sign < 0)
	{
		if (tot_res > 0 && sign < 0)
			return (0);
	}
	else
	{
		if (tot_res < 0 && sign > 0)
			return (-1);
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	long		res;
	int			sign;
	size_t		i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + str[i] - '0';
		if (min_max_check(res * sign, sign) != 1)
			return (min_max_check(res * sign, sign));
		i++;
	}
	return ((int)(sign * res));
}

static void	send_bit(pid_t pid, char message)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(100);
		if ((message & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
}

static void	send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_bit(pid, str[i]);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid > 99999)
		return (0);
	send_message(pid, argv[2]);
	return (0);
}
