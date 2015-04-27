/*
 * main.c
 *
 *  Created on: 24/4/2015
 *      Author: utnso
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/mman.h>

int getFileSize(FILE* fd) {
	fseek(fd,0L,SEEK_END);
	int a = ftell(fd);
	fseek(fd,0L,SEEK_SET);
	return a;
}

void redirectStdin(FILE* file) {
	dup2(fileno(file),STDIN_FILENO);
}

void redirectStdout(FILE* file) {
	dup2(fileno(file),STDOUT_FILENO);
}

void redirectSTDIO(FILE * stdin, FILE* stdout) {
	;
}

int main(int argc, char** argv) {
	FILE* archivo = fopen("caca.caca","r+");

	int size = getFileSize(archivo);

	char* addrMapped = mmap(NULL,size,PROT_READ | PROT_WRITE, MAP_SHARED,fileno(archivo),0);

	int i;
	for(i = 0; i < size; i++) {
		printf("%c",addrMapped[i]);
	}
	sprintf(addrMapped,"asasasas");
	printf("\n%s",addrMapped);


	munmap(addrMapped,size);

	return EXIT_SUCCESS;
}

int writeInFile() {
	return 2;
}

