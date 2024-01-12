/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_child_com.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:48:21 by izperez           #+#    #+#             */
/*   Updated: 2024/01/12 13:22:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	sig_handler_child(int signum)
{
	printf("\n** CHLID **\n");
	printf("Received a signal from parent\n");
	sleep(1);
	kill(getppid(), SIGUSR1);
}

void	sig_handler_parent(int signum)
{
	printf("\n** PARENT **\n");
	printf("Received a response signal from child\n");
}

int	main()
{
	pid_t pid;
	
	/* Fork() creates child process */
	pid = fork();
	if (pid < 0)
	{
		printf("Fork failed\n");
		exit(1);
	}
	/* Child process */
	else if (pid == 0)
	{
		signal(SIGUSR1, sig_handler_child); //Register signal handler
		printf("Child: waiting for signal\n");
		pause();
	}
	/* Parent process */
	else
	{
		signal(SIGUSR1, sig_handler_parent);
		sleep(1);
		printf("Parent: sending signal to child\n");
		kill(pid, SIGUSR1);
		printf("Parent: waiting for response\n");
		pause();
	}
	return (0);
}

/* OUTPUT */

/* 
En resumen, este código muestra un ejemplo de comunicación entre un proceso padre y un proceso hijo utilizando señales.
El proceso padre envía una señal al proceso hijo, que está esperando la señal y responde al proceso padre.

Child: waiting for signal
Parent: sending signal to child
Parent: waiting for response

** CHLID **
Received a signal from parent

** PARENT **
Received a response signal from child 
*/

/* 

1. Se declara una variable pid de tipo pid_t, que se utilizará para almacenar el identificador del proceso hijo.

2. Se llama a la función fork(). Esta función crea un nuevo proceso hijo duplicando el proceso actual.
Después de la llamada a fork(), hay dos procesos en ejecución: el proceso padre y el proceso hijo.

3. Se verifica el valor devuelto por fork(). Si el valor es menor que 0, significa que la llamada a fork() ha fallado
y se imprime un mensaje de error. En este caso, el programa sale con un código de error utilizando la función exit().

4. Si el valor devuelto por fork() es igual a 0, significa que el proceso actual es el proceso hijo.
En este caso, se registra un manejador de señal utilizando la función signal().
La señal que se está manejando es SIGUSR1, que es una señal definida por el usuario.
Después de registrar el manejador de señal, se imprime un mensaje indicando que el proceso hijo está esperando 
una señal y se pausa la ejecución del proceso hijo utilizando la función pause(), lo que hace que el proceso se
suspenda hasta que se reciba una señal.

5. Si el valor devuelto por fork() es mayor que 0, significa que el proceso actual es el proceso padre. En este caso,
también se registra un manejador de señal utilizando la función signal(). Luego, el proceso padre espera un segundo
utilizando la función sleep() para asegurarse de que el proceso hijo esté listo para recibir la señal.
Después de esperar, se imprime un mensaje indicando que el proceso padre está enviando una señal al proceso hijo
utilizando la función kill(), que envía una señal a un proceso específico. Finalmente, se imprime otro mensaje indicando
que el proceso padre está esperando una respuesta y se pausa la ejecución del proceso padre utilizando la función pause().

6. El programa finaliza con un valor de retorno de 0, indicando que la ejecución del programa ha finalizado correctamente. 
*/