#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char **argv){

	char *src, *dst;
    int file_in, file_out;

    struct stat buffstat;
    file_in = open("ex1.txt", O_RDONLY);
    

    fstat(file_in, &buffstat);

    src = mmap(NULL, buffstat.st_size, PROT_READ, MAP_PRIVATE, file_in, 0);

    file_out = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

    ftruncate(file_out, buffstat.st_size);

    dst = mmap(NULL, buffstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_out, 0);


    memcpy(dst, src, buffstat.st_size);

    munmap(src, buffstat.st_size);
    munmap(dst, buffstat.st_size);

    close(file_in);
    close(file_out);

    return 0;
}
