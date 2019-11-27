#include "AFun.h"



int main ( int argc, char *argv[] ) {
	
	//Lista dinamica de Rps (los sockets a c/u de ellos)
	Lista *listaRps = crearLista(void);

	//pointer de shm:
	void *shm = conectarSHM(SHM_PATH); 

	int readfds[100];
	int writefds[100];
	char *buffers[100];
	
	int newfd, sockEsc = sockEscuchar(PUERTO_A);

	while(1) { //Curso normal
			
		newfd = selectSockets (readfds, writefds, sockEsc, SEL_TIMEOUT, buffers, leerDatos, shm, devolverMsj);	
			
		//Si tengo un nuevo socket (con algun nuevo Rp) lo agreso para leer y escribir:
		if (newfd > 0) {
			
			agregarNodo (listaRps, newfd);				
			
			readfds[lista.cant] = newfd;
			writefds[lista.cant] = newfd;
			
		}			
	}

	close(sockEsc);
	liberarDatos(listaRps);
	
	return EXIT_SUCCESS;
}


