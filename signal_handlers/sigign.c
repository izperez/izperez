/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:02:26 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 12:09:07 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* IGNORE SIGNALS EXAMPLE */

int	main()
{
	//Register signal handler for ignoring the signal
	signal(SIGINT, SIG_IGN); 
	int	i;

	i = 1;
	while (i++) //infinite loop
	{
		printf("%d: ** MAIN **\n", i);
		sleep(1);
	}
	return (0);
}

/* OUTPUT */

/* 
 * Handler function is register to SIG_IGN(),
 * signal is generating but the action is ignored.
2: ** MAIN **
3: ** MAIN **
4: ** MAIN **
^C5: ** MAIN **
6: ** MAIN **
^C7: ** MAIN **
8: ** MAIN **
^Z
[5]  + 45998 suspended  ./sigign 
*/