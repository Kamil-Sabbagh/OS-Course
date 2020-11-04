#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char** argv) {
	int temp ; 
	if  ( (argc >=2 && strcmp(argv[1], "-a")) == 0 )  
	  temp = 1  ;
	else 
	  temp = 0   ; 
	if (argc == 1 || argc == 2 && temp) {
		puts("specifi at least one file");
		return 0;
	}
	int arr[argc] ;
	
	for (int i = 1 + temp; i < argc; i++) { 
	
		arr[i] = open(argv[i], O_RDWR | O_CREAT | (temp ? temp : 0), S_IWUSR | S_IRUSR);
	}	
	
	arr[temp] = 1; 

	char buffer[5];
	
	while (read(0, buffer, 5 ) != 0) {
	 
		for (int i = temp; i < argc; i++) 
		{ 
			write(arr[i], buffer, strlen(buffer));
		}
	}

	for (int i = 1 + temp; i < argc; i++) { 
		close(arr[i]);
	}

	return 0;
}
