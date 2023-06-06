/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:55 by minson            #+#    #+#             */
/*   Updated: 2023/06/06 15:08:53 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_putchar_fd(long nb, int fd)
{
	char	c;

	c = nb + '0';
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * (-1);
		ft_putnbr_fd(nbr, fd);
	}
	else if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else if (nbr <= 9)
		ft_putnbr_putchar_fd(nbr, fd);
}

static void	handler(int signal)
{
	static int		recieve_bit;
	static char		bit_tmp;

	if (signal == SIGUSR1)
		bit_tmp |= (1 << recieve_bit);
	recieve_bit++;
	if (recieve_bit == 8)
	{
		ft_putchar_fd(bit_tmp, 1);
		recieve_bit = 0;
		bit_tmp = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (0);
	write(1, "Process ID => ", 14);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
