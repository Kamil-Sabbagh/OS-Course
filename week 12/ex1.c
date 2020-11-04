#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	FILE *random = fopen("/dev/random", "r");
	char temp;
	int i = 0;
	while(i<20){
	
	fread(&temp,1,1,random);
	
	if( (int)temp > 127 || (int)temp < 33 ) continue ; 
	printf("%c", temp );
	i++;
	   
	}
	printf("\n");
	fclose(random);
}
