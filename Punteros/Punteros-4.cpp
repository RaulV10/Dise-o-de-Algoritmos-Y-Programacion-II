//
//  Punteros-4.cpp
//  
//
//  Created by Raul Villarreal on 2/1/17.
//
//

#include <stdio.h>
#include <string.h>

int main() {
    
    printf("\n*****************************************\n\n");
    
    int tam, i, contas=0;
    char nombre[30];
    char *p = NULL;
    printf("Introduzca su nombre: ");
    fflush(stdin);
    gets(nombre);
    tam = strlen(nombre);
    p = nombre; // p = &nombre[0];
    
    for (i = 0; i < tam; i++) {
        if (*p == 'a') /* El asterisco se utiliza para obtener el valor, si no se utiliza obtiene la memoria */ {
            contas++;
        }
        p++;
    }
    
    p = p - tam;
    
    printf("El nombre: %s tiene %d letras 'a'\n", p, contas);
    
    printf("\n*****************************************\n");
    
    return 0;
}
