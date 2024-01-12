/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendsig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:23:42 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:34:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A process also can explicitly send signal to itsel or to another process.
 * Both function can be used for sending signals, (are declared in signal.h) */

/* Send signal 'signum' to the calling process itself.
 * Returns 0 if sucess and nonzero if fails.  */
int	raise(int signum)
{
	
}

/* Send signal 'signum' to a process >= 1 specified by pid. */
int	kill(pid_t pid, int signum)
{
	
}