#include <stdio.h>
#include <stdlib.h>

int i = 5;

#define SUCCESS return 0;

#define CODE "#include <stdio.h>%1$c#include <stdlib.h>%1$c%1$cint i = %2$d;%1$c%1$c#define SUCCESS return 0;%1$c#define CODE %3$c%4$s%3$c%1$c%1$cint main(void){%1$c    int next = i - 1;%1$c    if(next < 0) next = 0;%1$c    char filename[50];%1$c    sprintf(filename, %3$cSully_%%d.c%3$c, i);%1$c    FILE *f = fopen(filename, %3$cw%3$c);%1$c    if(!f) return 1;%1$c    fprintf(f, CODE, 10, next, 34, CODE);%1$c    fclose(f);%1$c    if(i > 0){%1$c        char cmd[200];%1$c        sprintf(cmd, %3$cclang -Wall -Wextra -Werror %%s -o Sully_%%d && ./Sully_%%d%3$c, filename, next, next);%1$c        system(cmd);%1$c    }%1$c    SUCCESS;%1$c}"

int main(void) {
    int next = i - 1;
    if (next < 0)
        next = 0;

    char filename[50];
    sprintf(filename, "Sully_%d.c", i);
    FILE *f = fopen(filename, "w");
    if (!f) return 1;

    // Fully positional arguments: %1$c = newline, %2$d = next value of i, %3$c = quote, %4$s = CODE itself
    fprintf(f, CODE, 10, next, 34, CODE);
    fclose(f);

    if (i > 0) {
        char cmd[200];
        sprintf(cmd, "clang -Wall -Wextra -Werror %s -o Sully_%d && ./Sully_%d", filename, next, next);
        system(cmd);
    }

    SUCCESS;
}
