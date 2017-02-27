//
//  Punteros-3.cpp
//
//
//  Created by Raul Villarreal on 2/1/17.
//
//

#include "Punteros-2.hpp"
#include <stdio.h>

int main() {
    int n, i, *p;
    
    do{
        printf("Cuantos n%cmeros\n", 163);
        scanf("%d", &n);
        
        if((n < 1) || (n > 32767)) {
            printf("El valor debe ser entre 1 y 32767\n");
        }
    }while((n < 1) || (n > 32767));
    
    int arreglo[n];
    
    for(i = 0; i < n; i++) {
        printf("Introduzca un n%cmero: ", 163);
        scanf("%d", &arreglo[i]);
    }
    
    // p apunte al primer elemento del arreglo
    p = arreglo;
    
    printf("Los numeros son:\n");
    
    for(i = 0; i < n; i++) {
        printf("- > %d\n", *p);
        p++; // p = p+1;
    }
    
    return 0;
}
