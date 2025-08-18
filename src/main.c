#include <stdio.h>
#include "semantico/semantico.h"

int yyparse(void);

int main(void) {
    printf("Starting parser...\n");
    printf("Escribe tu código y presiona Ctrl+D para finalizar la entrada.\n");
    if (yyparse() == 0) {
        if (error_semantico) {
            printf("Error semántico\n");
        } else {
            printf("Cadena válida\n");
        }
    }
    return 0;
}