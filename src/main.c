#include <stdio.h>

int yyparse(void);

int main(void) {
    printf("Starting parser...\n");
    if (yyparse() == 0) {
        printf("Cadena válida");
    }
    return 0;
}