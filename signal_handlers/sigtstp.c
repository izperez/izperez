/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:29:37 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 11:25:48 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//aparece este mensaje cuando pulsas c + z en la terminal.
void	handle_sigtstp(int sig)
{
	printf("Stop NoNO\n");
}

int	main(int ac, char *av[])
{
	//versión larga con estructura
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);	

	/* versión corta, sin estructura
	 * sigaction(SIGTSTP, &sa, NULL);
	 */

	int	x;
	printf("Introduce un número; ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}