#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
	char word[20];

	while(true){
		
		fgets(word,sizeof(word),stdin);
		if(strcmp("exit\n",word) == 0)
			break;
		fork();
		system(word);
	}
}
