/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigusr1_raise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:41:07 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:47:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	printf("\n** HANDLER **\n");
}

/* The process send SIGUSR1 signal to itsel using kill().
 * Getpid() is used to get the process ID of itself. */
int	main()
{
	pid_t pid;
	signal(SIGUSR1, sig_handler);
	printf("*** MAIN ***\n");
	pid = getpid();
	kill(pid, SIGUSR1);
	printf ("* MAIN *\n");
	return (0);
}

/* OUTPUT */
/* 
*** MAIN ***

** HANDLER **
* MAIN *
 */