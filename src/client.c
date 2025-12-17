/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:32:12 by miniplop          #+#    #+#             */
/*   Updated: 2025/12/17 16:08:02 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static volatile int	g_ack = 0;

static void	ack_handler(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
		g_ack = 1;
	if (signum == SIGUSR2)
		g_ack = 2;
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack)
			pause();
		if (g_ack == 2)
			return ;
		i--;
	}
}

static int	ft_pars(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		exit(1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] > '9' || argv[1][i] < '0')
		{
			write(2, "Invalid <PID>\n", 14);
			exit(1);
		}
		i++;
	}
	pid = ft_atoi(argv[1]);
	return (pid);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	pid = ft_pars(argc, argv);
	i = kill(pid, 0);
	if (i != 0)
	{
		write(2, "Invalid <PID>\n", 14);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
