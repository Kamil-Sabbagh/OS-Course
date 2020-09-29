#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

void *myrealloc (int *ptr, size_t size){
	void *newptr;
	int msize;
	msize = sizeof(ptr);
	newptr = malloc(size);
	memcpy(newptr,ptr,msize);
	free(ptr);
	return newptr;
}

int main()
{
	int n = 5;
	int *arr = (int*) malloc (sizeof(int)*n);
	for(int i = 0; i< n ;i++){
		arr[i] = i;
		printf("%d ", arr[i] );
	}
	printf("\n");
	n = 3;
	int *new = (int*) myrealloc(arr,n);
	for(int i = 0; i< n;i++ ){
		new[i] = i;
		printf("%d ", new[i] );
	}
	printf("\n");
	return 0;
}
