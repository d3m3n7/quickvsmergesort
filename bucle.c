
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

char buf [80];

void muta_a_PS ()
{
			for(int i= 0; i< 500000000; i++);
  execlp ("make", "make","HACER_3_PRUEBAS", (char *) NULL);
  //error_y_exit("Ha fallado la mutación al ps", 1);//si executa aquesta linia vol dir q no ha mutat
}

/*
float elapsed_time(clock_t* start, clock_t* end){
//The C library function clock_t clock(void) returns the number of clock ticks elapsed since the program was launched. To get the number of seconds used by the CPU, you will need to divide by CLOCKS_PER_SEC.
	return (double)(end - start) / CLOCKS_PER_SEC;
}
*/

int main (int argc, char *argv[])
{
	int pid = fork ();
	if (pid == 0) {
		execlp("make","make", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	sprintf (buf,"STARTING %d ITERATIONS\n",atoi (argv[1]));
	time_t start_t, end_t;
	double diff_t;
	time(&start_t);
	write(1,buf,strlen(buf));
	for (int i = 0; i < atoi (argv[1]); ++i){
		pid = fork ();
		if (pid == 0)
		  {
		    muta_a_PS();
		    exit (-1);
		  }
	    	if (pid > 0){
			while ((waitpid (-1, NULL, 0)) > 0);
			time(&end_t);
			sprintf (buf,"\nITERACIO ~~~ %d/%d | ELAPSED TIME: %f sec\n",i + 1,atoi (argv[1]),difftime(end_t,start_t));
			write(1,buf,strlen(buf));
		}
	}
	pid = fork ();
	if (pid == 0) {
		execlp ("make", "make","MAKE_LOGS", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	pid = fork ();
	if (pid == 0) {
		execlp ("make", "make","fclean", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	pid = fork();
	if (pid == 0) {
		execlp ("make", "make","clean", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	sprintf (buf,">>>LOG_M.log<<<\n");
	write(1,buf,strlen(buf));

	pid = fork ();
	if (pid == 0) {
		execlp ("cat", "cat","LOG_M.log", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	sprintf (buf,"\n>>>LOG_Q.log<<<\n");
	write(1,buf,strlen(buf));
	pid = fork ();
	if (pid == 0) {
		execlp ("cat", "cat","LOG_Q.log", (char *) NULL);
		exit(-1);
	}
	waitpid(-1,NULL,0);
	exit(1);
}

//make -f makefile_5 clean	<--	AQUESTA ES L'ESTRUCTURA D'UN MAKEFILE BEN FET (estic cridant funcio clean del makefile_5)
/*	makefile_5 <~~ nom_fitxer
all: suma

suma: suma.o mis_funciones.o
	gcc -o suma suma.o mis_funciones.o

suma.o: suma.c
	gcc -c suma.c

mis_funciones.o: mis_funciones.c mis_funciones.h
	gcc -c mis_funciones.c -I .

clean:
	rm mis_funciones.o
	rm suma.o

fclean: clean
	rm suma
*/

