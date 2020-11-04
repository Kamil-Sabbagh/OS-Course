#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 5

int main(int argc, char** argv) {
	int append = (argc >=2 && strcmp(argv[1], "-a")) == 0 ? 1 : 0;
	if (argc == 1 || argc == 2 && append) {
		puts("at least one file should be specified");
		return 0;
	}

	int fd[argc];
	for (int i = 1 + append; i < argc; i++) { //for each file
		fd[i] = open(argv[i], O_RDWR | O_CREAT | (append ? O_APPEND : 0), S_IWUSR | S_IRUSR);
	}
	fd[append] = 1; //stdout

	char buf[BUF_SIZE];
	while (read(0, buf, BUF_SIZE) != 0) {
		for (int i = append; i < argc; i++) { //for each file AND stdout
			write(fd[i], buf, strlen(buf));
		}
	}

	for (int i = 1 + append; i < argc; i++) { //for each file
		close(fd[i]);
	}

	return 0;
}
