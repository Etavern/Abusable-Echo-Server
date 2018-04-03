#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

void do_echo(int comm, char str[25]);

int  main(){
	char str[25];
	int listener;
	int comm;
	struct sockaddr_in servaddr;
	
	listener = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(6660);
	
	bind(listener, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listener, 10);

	while(true){
		comm = accept(listener, (struct sockaddr *) NULL, NULL);
		bzero(str, 25);
		read(comm, str, 25);
		do_echo(comm, str);
	}
}

void do_echo(int comm, char str[25]){
         printf("Echo: %s\n", str);
         write(comm, str, strlen(str)+1);
}

