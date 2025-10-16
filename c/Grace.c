/* Grace program: writes itself to Grace_kid.c */
#include <stdio.h>

#define FILE_NAME "Grace_kid.c"
#define SUCCESS return 0;
#define CHECK_FILE if(!f) return 1;

#define CODE "/* Grace program: writes itself to Grace_kid.c */%1$c#include <stdio.h>%1$c%1$c#define FILE_NAME %2$cGrace_kid.c%2$c%1$c#define SUCCESS return 0;%1$c#define CHECK_FILE if(!f) return 1;%1$c%1$c#define CODE %2$c%3$s%2$c%1$c%1$c#define FT int main(void){FILE *f=fopen(FILE_NAME,%2$cw%2$c);CHECK_FILE fprintf(f, CODE, 10, 34, CODE);fclose(f);printf(%2$cCopy created!\\n%2$c);SUCCESS;}%1$cFT%1$c"

#define FT int main(void){FILE *f=fopen(FILE_NAME,"w");CHECK_FILE fprintf(f,CODE,10,34,CODE);fclose(f);printf("Copy created!\\n");SUCCESS;}
FT
