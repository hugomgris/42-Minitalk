/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:22:43 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/12 10:04:54 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_error_output(int i)
{
	if (i == 0)
	{
		ft_printf("KILL error.\n");
		exit (1);
	}
	if (i == 1)
	{
		ft_printf("SIGACTION error.\n");
		exit(1);
	}
}

void	mt_terminate(int pid)
{
	static int	i = 0;

	if (i <= 8)
		if (kill(pid, SIGUSR1) == -1)
			mt_error_output(0);
	i++;
}

void	mt_send_sign(int pid, char *msg)
{
	static int	bit = 0;
	static char	*msg_copy = 0;

	if (msg)
		msg_copy = msg;
	if (*msg_copy)
	{
		if ((((unsigned char)*msg_copy >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				mt_error_output(0);
		if ((((unsigned char)*msg_copy >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				mt_error_output(0);
		bit++;
		if (bit == 8)
		{
			msg_copy++;
			bit = 0;
		}
	}
	if (!(*msg_copy))
		mt_terminate(pid);
}

void	mt_ack(int sig, siginfo_t *info, void *context)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		mt_send_sign(id, NULL);
	if (sig == SIGUSR2)
	{
		ft_printf("The message arrived at the server\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = mt_ack;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		mt_error_output(1);
	if (argc != 3)
	{
		ft_printf("Input error. Try ./client <PID> <MSG>");
		exit(EXIT_FAILURE);
	}
	mt_send_sign(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
