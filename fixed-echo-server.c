#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

void do_echo(char str[100], int comm);
void print_explicit();

int  main(){
	char str[100];
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
		bzero(str, 100);
		read(comm, str, 100);
		do_echo(str, comm);
	}
}

void do_echo(char str[100], int comm){	
	char to_echo[50];
	strncpy(to_echo, str, 50);
	printf("Echo: %s\n", to_echo);
	write(comm, str, strlen(str)+1);
}

void print_explicit(){
	puts("OH NO, MY EXPLICIT IS EXPOSED!");
}

