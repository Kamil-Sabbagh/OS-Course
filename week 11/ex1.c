#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	int file;
	file = open("ex1.txt", O_RDWR);
	struct stat buffstat;
fstat(file, &buffstat);
  void* out;

  if ((out = (char*)mmap(0, buffstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0)) == MAP_FAILED)
  {
    fprintf(stderr, "All is bad\n");
    return 1;
  }
  memcpy(out, "This is a nice day", buffstat.st_size);
return 0;
}
