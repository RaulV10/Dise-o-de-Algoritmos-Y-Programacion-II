//
//  Punteros-4b.cpp
//
//
//  Created by Raul Villarreal on 2/13/17.
//
//

#include <stdio.h>
#include <string.h>

int main() {
    
    // prototipo de la funcion
    int FCuentaAs(char *, int);
    
    printf("\n*****************************************\n\n");
    
    int tam, contas=0;
    char nombre[30];
    char *p = NULL;
    printf("Introduzca su nombre: ");
    fflush(stdin);
    gets(nombre);
    tam = strlen(nombre);
    p = nombre; // p = &nombre[0];
    
    //contas = FCuentaAs(p, tam);
    
    printf("El nombre: %s tiene %d letras 'a'\n", p, FCuentaAs(p, tam));
    
    printf("\n*****************************************\n");
    
    return 0;
}

int FCuentaAs(char *p, int tam) {
    
    int i, contas = 0;
    
    for (i = 0; i < tam; i++) {
        if (*(p+i) == 'a') /* El asterisco se utiliza para obtener el valor, si no se utiliza obtiene la memoria */ {
            contas++;
        }
    }
    
    return contas;
    
}
