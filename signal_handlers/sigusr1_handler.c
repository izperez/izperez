/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigusr1_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:35:05 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:40:00 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

void sig_handler(int signum)
{
	printf(" ** HANDLER **\n");
}
/* The process send SIGUSR1 signal to itsel using raise funcion. */
int	main()
{
	signal(SIGUSR1, sig_handler); //Register signal handler
	printf(" ** MAIN **\n");
	raise(SIGUSR1);
	printf(" ** MAIN **\n");
	return (0);
}

/* OUTPUT */

/* 
 * ** MAIN **
 ** HANDLER **
 ** MAIN **
  */