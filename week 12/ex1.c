#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	FILE *random = fopen("/dev/random", "r");
	char check;
	int i = 0;
	while(i<20){
	
	fread(&check,1,1,random);
	
	if((int)check >=33 && (int)check <=127){
		printf("%c", check);
		i++;
	}
	}
	printf("\n");
	fclose(random);
}
