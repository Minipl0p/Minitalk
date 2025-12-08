/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:32:12 by miniplop          #+#    #+#             */
/*   Updated: 2025/12/08 15:17:14 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static volatile int g_ack = 0;

static void ack_handler(int signum)
{
    (void)signum;
    g_ack = 1;
}

static void send_char(int pid, char c)
{
    int i = 7;

    while (i >= 0)
    {
        g_ack = 0;

        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);

        while (!g_ack)
            usleep(50);
        i--;
    }
}

int main(int argc, char **argv)
{
	int	i;
	int	pid;

    if (argc != 3)
    {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    if (pid <= 0)
        return (1);

    signal(SIGUSR1, ack_handler);
    i = 0;
    while (argv[2][i])
    {
        send_char(pid, argv[2][i]);
        i++;
    }
    send_char(pid, '\0');
    return (0);
}
