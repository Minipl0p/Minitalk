/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:12:04 by miniplop          #+#    #+#             */
/*   Updated: 2025/12/17 16:23:13 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static char	*set_str(char *str, unsigned char c, pid_t *cur_pid)
{
	char	*tmp;
	char	char_to_str[2];

	if (!str)
	{
		tmp = ft_calloc(sizeof(char), 2);
		if (!tmp)
			return (NULL);
		tmp[0] = c;
		return (tmp);
	}
	if (c == '\0')
	{
		write(1, str, ft_strlen(str));
		free(str);
		*cur_pid = 0;
		return (NULL);
	}
	char_to_str[0] = c;
	char_to_str[1] = '\0';
	tmp = ft_strjoin(str, char_to_str);
	free (str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			cur_pid = 0;
	static unsigned char	c = 0;
	static int				bit = 0;
	static char				*str = NULL;

	(void)context;
	if (cur_pid == 0)
		cur_pid = info->si_pid;
	if (info->si_pid != cur_pid)
		return ;
	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	if (++bit == 8)
	{
		str = set_str(str, c, &cur_pid);
		c = 0;
		bit = 0;
		if (!str)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
