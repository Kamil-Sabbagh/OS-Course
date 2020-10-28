/*#include <stdio.h>
#include <unistd.h>
int main(void) {
printf("Hello");
fork();
printf("\n");
return 0;
}
*/


#include <stdio.h>
#include <unistd.h>
int main(void) {
printf("Hello\n");
fork();
printf("\n");
return 0;
}
