//
//  Punteros-7.cpp
//  
//
//  Created by Raul Villarreal on 2/13/17.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* FPar(int *num);

int main() {
    int *num;
    char *Res;
    // Reserva de funciones
    num = (int *) malloc(sizeof(int));
    Res = (char *) malloc(10*sizeof(char));
    
    // Almacenar el numero
    printf("Introduzca el numero: ");
    scanf("%d", num);
    
    Res = FPar(num);
    
    printf("%d es %s\n", *num, Res);
    
    free(num);
    free(Res);
    
    return 0;
}

// Funcion

char* FPar(int *num) {
    char *Resu;
    Resu = (char *) malloc(10*sizeof(char));
    if(*num%2==0) {
        strcpy(Resu, "Par");
    } else {
        strcpy(Resu, "Impar");
    }
    
    return Resu;
}
