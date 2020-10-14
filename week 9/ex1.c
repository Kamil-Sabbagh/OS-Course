#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct {
	int pageid;
	uint lutime;	
} PAGE;


int handle_ref(PAGE* arr, uint length, uint pageid, uint tick) ; 


int main(int argc, char** argv) {



	char fpath[256];
	char buf[10];
	char *bp = buf;
	uint npages, tick;
	FILE *fp;
	int ch;
	uint hits, refs;
	
	if (argc > 1) npages = atoi(argv[1]);
	if (argc > 2) strcpy(fpath, argv[2]);
	else strcpy(fpath, input.txt);

	PAGE* array = (PAGE*)malloc(npages * sizeof(array));
	for (int i = 0; i < npages; i++) array[i].pageid = -1;

	fp = fopen(fpath, "r");

	tick = 0;
	hits = 0;
	refs = 0;
	while((ch = fgetc(fp)) != EOF) {
		if (ch >= '0' && ch <= '9') {
			*(bp++) = ch;	// add to buffer
		} else if (ch == ' ') {
			if (bp != buf) {
				*bp = '\0'; 	// make sure the string is closed
				bp = buf;	// reset the pointer
				hits += handle_ref(array, npages, atoi(buf), tick);	// handle the reference
				refs++;		// increase the counters
				tick++;
			}
		} else if (ch == '\n') {	// check last time then quit
			if (bp != buf) {
				hits += handle_ref(array, npages, atoi(buf), tick);
				refs++;
			}
			break;
		} 
			
	}

	printf("The Hit/Miss ratio is: %f\n", (float)hits/(refs-hits)); // hit/miss ratio

	return 0;
}



int handle_ref(PAGE* arr, uint length, uint pageid, uint tick) {
	PAGE page;
	page.pageid = pageid;
	page.lutime = tick;
	
	for (int i = 0; i < length; i++) {
		if (arr[i].pageid == -1) { 
			arr[i] = page;
			return 0;
		}

		if (arr[i].pageid == page.pageid) {
			arr[i] = page;
			return 1 ;
		}
	}

	int ri = 0;
	for (int i = 1; i < length; i++) {
		if (arr[i].lutime < arr[ri].lutime) ri = i;
	}

	arr[ri] = page;
	return 0;
}
