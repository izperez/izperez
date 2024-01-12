/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:42:14 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:12:55 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* BASIC SIGNAL HANDLER EXAMPLE */
void	sig_handler(int sig_num)
{
	//Return type of the handler function should be void
	printf("\n ** HANDLER FUNC **\n");
}

int	main()
{
	int	i;

	i = 1;
	signal(SIGINT, sig_handler); //Register signal handler
	while (i++) //Infinite loop
	{
		printf("%d: ** MAIN **\n", i);
		sleep(1); //Delay for 1 second
	}
	return (0);
}

/* OUTPUT */

/* 
 * When pressing ctrl+c, main function execution stop 
 * and the handler function of the signal is invoked.
 * After completion of handler(), main() is resumed.
2: ** MAIN **
3: ** MAIN **
4: ** MAIN **
5: ** MAIN **
6: ** MAIN **
^C
 ** HANDLER FUNC **
7: ** MAIN **
8: ** MAIN **
9: ** MAIN **
10: ** MAIN **
11: ** MAIN **
^Z 
*/