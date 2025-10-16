#include <stdio.h>

/* Fonction supplémentaire : helper */
char *helper(void) {
    char *s =
"#include <stdio.h>%c%c"
"/* Fonction supplémentaire : helper */%c"
"char *helper(void) {%c"
"%cchar *s = %c%s%c;%c"
"%creturn s;%c"
"}%c%c"
"int main(void) {%c"
"%c/* Commentaire présent DANS main */%c"
"%cchar *s = helper();%c"
"%cprintf(s,10, 10, 10, 10,9, 34, s, 34, 10, 9, 10, 10, 10, 10, 9, 10, 9, 10,  9, 10, 10, 10, 10);%c"
"%creturn 0;%c"
"}%c";
    return s;
}

int main(void) {
    /* Commentaire présent DANS main */
    char *s = helper();
    printf(s,10, 10, 10, 10,9, 34, s, 34, 10, 9, 10, 10, 10, 10, 9, 10, 9, 10,  9, 10, 10, 10, 10); 
    return 0;
}
