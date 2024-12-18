/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:23:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/12 10:04:32 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	mt_error_output(int i)
{
	if (i == 0)
	{
		ft_printf("KILL error.\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("SIGACTION error.\n");
		exit(1);
	}
}

//Handles each bit of incoming msg signals
//SIGUSR1 (0) is not handled
//SIGUSR2 (1) the accumulated val is updated by adding current bit
//bit is then shifted left by multiplying it times 2
void	mt_process_bit(int sig, unsigned char *val, int *bit)
{
	if (sig == SIGUSR2)
		*val += *bit;
	*bit *= 2;
}

//Writes the chars of the received msg, val after val (char after char)
//if val = \0 (00000000), it sends back SIGUSR2 to client to acknowledge end
//it then prints it's own acknowledgement of reception and process finalization
void	mt_complete_char(int *bit, unsigned char *val, int id)
{
	*bit = 1;
	if (*val == 0)
	{
		if (kill(id, SIGUSR2) == -1)
			mt_error_output(0);
		ft_printf("\nMessage received and processed.\n");
	}
	write(1, val, 1);
	*val = 0;
}

//Function to handle receives signals.
//Stores client PID to send acknowledgements back.
//val stores the unigned char value to be represented (0-255)
//bit tracks TOTAL amount of bits received accross all chars in msg.
//id stores PID. 
//msg is processed bit by bit, writing each char after its 8 bits
//have ben rebuilt. When \0 char is received, termination is called.
void	mt_signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	val = 0;
	static int				bit = 1;
	static int				id = 0;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context;
	mt_process_bit(sig, &val, &bit);
	if (bit == 256)
		mt_complete_char(&bit, &val, id);
	if (kill(id, SIGUSR1) == -1)
		mt_error_output(0);
}

//Straightforward initialization, almost equal to the client one
//pid_t is a typedef of int specifically used to store PIDs (readability).
//Alias avaiable in <signal.h>
int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = mt_signal_handler;
	sigemptyset(&action.sa_mask);
	pid = getpid();
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		mt_error_output(1);
	ft_printf("INITIALIZING SERVER!\n");
	ft_printf("Server PID: %d\nWaiting for signals...\n", pid);
	while (1)
		pause();
	return (0);
}
