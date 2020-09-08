#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	for(int i = 0; i < 5; i++){
		fork();
		sleep(5);
		system("pstree -p 9307");
	}
}
