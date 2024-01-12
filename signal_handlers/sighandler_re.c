/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:09:31 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:21:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* REREGISTER SIGNAL HANDLER EXAMPLE */
void	sig_handler(int signum)
{
	printf("\nInside hanlder function\n");
	signal(SIGINT, SIG_DFL); //Re Register signal handler for default action
}

int	main()
{
	signal(SIGINT, sig_handler); //Register signal handler
	int	i;

	i = 1;
	while (i++) //Infinite loop
	{
		printf("%d: ** MAIN **\n", i);
		sleep(1); //Delay for 1 second
	}
	return (0);
}

/* OUTPUT */

/* 
 * 1.CTR+C, the handler function invoked.
 * Handler() -> Register to SIG_DFL for default action of the signal.
 * 2.CTR*C, process is terminated. (default action of SIGINT).
2: ** MAIN **
3: ** MAIN **
4: ** MAIN **
^C
Inside hanlder function
5: ** MAIN **
6: ** MAIN **
^C 
*/