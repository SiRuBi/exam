#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int glob = 6; /* i n i t i a l i z ed data */
int main( void) {
	int var ; /* automatic variable */
	pid_t pid ;
	var = 88;
	printf( "before vfork\n" ) ;
	if( ( pid = vfork ( ) ) < 0) {
		perror ( " vfork error " ) ;
	} else if ( pid == 0) { /* child */
		glob++; /* modify parent ’ s variables */
		var++;
		_exit (0) ; /* child terminates */
	} /* parent continues here . . . */
	printf ( "pid = %d, glob = %d, var = %d\n" , getpid ( ) ,
			glob , var ) ;
	exit( EXIT_SUCCESS ) ;
}
